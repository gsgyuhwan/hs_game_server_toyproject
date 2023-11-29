#pragma once
#include "Match.h"

Match::Match(std::unique_ptr<Session> session1, std::unique_ptr<Session> session2, std::unordered_set<std::shared_ptr<Match>>& match_set) :
	turn_(),
	match_set_(match_set)
{
	sessions_[0] = std::move(session1);
	sessions_[1] = std::move(session2);
	boards_[0] = std::make_unique<Board>();
	boards_[1] = std::make_unique<Board>();
	players_[0] = std::make_unique<Player>(session1.get()->GetUserID());
	players_[1] = std::make_unique<Player>(session1.get()->GetUserID());

	StartMatch();
}

void Match::PlayMove(Move& move)
{
	switch (move.move_type) 
	{
	case MoveType::TurnEnd:
	{
		turn_ = turn_ ^ turn_;
		SendAllBoardState();
		ReadNextMove();
		break;
	}
	case MoveType::Surrender:
	{
		match_set_.erase(shared_from_this());
		break;
	}
	case MoveType::HeroPower:
	{
		boards_[turn_].get()->BeforePlay(this, move);
		players_[turn_].get()->HeroPower();
		boards_[turn_].get()->AfterPlay(this, move);
		SendAllBoardState();
		ReadNextMove();
		break;
	}
	case MoveType::UnaryPlay:
	{
		boards_[turn_].get()->BeforePlay(this, move);
		UnaryPlay(move);
		boards_[turn_].get()->AfterPlay(this, move);
		SendAllBoardState();
		ReadNextMove();
		break;
	}
	case MoveType::BinaryPlay:
	{
		boards_[turn_].get()->BeforePlay(this, move);
		BinaryPlay(move);
		boards_[turn_].get()->AfterPlay(this, move);
		SendAllBoardState();
		ReadNextMove();
		break;
	}
	case MoveType::TernaryPlay:
	{
		boards_[turn_].get()->BeforePlay(this, move);
		TernaryPlay(move);
		boards_[turn_].get()->AfterPlay(this, move);
		SendAllBoardState();
		ReadNextMove();
		break;
	}
	}
}

void Match::StartMatch()
{
	SendAllBoardState();
	ReadNextMove();
}

BoardState Match::GetBoardState()
{
	BoardState bs{};
	return bs;
}

void Match::SendAllBoardState()
{
	std::for_each(sessions_.begin(), sessions_.end(), std::mem_fn(&Session::SendBoardState));
}

void Match::ReadNextMove()
{
	sessions_[turn_].get()->ReadMove();
}

void Match::UnaryPlay(Move& move)
{
	if (move.IsMyHand<FirstParam>())
	{
		players_[turn_].get()->PlaySpell(this, move);
	}
	else 
	{
		players_[turn_].get()->HeroPower(this, move);
	}
}

void Match::BinaryPlay(Move& move)
{
	if (move.first_param == FirstParam::Self)
	{
		players_[turn_].get()->AttackWeapon(this, move);
	}
	else if(move.IsMyBoard<FirstParam>())
	{
		MinionAttack(move.GetMyBoardPos<FirstParam>(), move.GetOpBoardPos<SecondParam>());
	}
	else if (move.IsMyBoard<SecondParam>())
	{
		players_[turn_].get()->PlayNonBattlecryMinion(this, move);
	}
	else if (move.IsOption<SecondParam>())
	{
		players_[turn_].get()->PlayTargetSpell(this, move);
	}
}

void Match::TernaryPlay(Move& move)
{
	if (move.IsOption<SecondParam>())
	{
		players_[turn_].get()->PlayChooseMinion(this, move);
	}
	else
	{
		players_[turn_].get()->PlayBattlecryMinion(this, move);
	}
}

void Match::MinionAttack(size_t pos1, size_t po2)
{
	Minion& attacker = boards_[turn_].get()->GetMinion(pos1);
	Minion& defender = boards_[turn_ ^ turn_].get()->GetMinion(pos2);
	if (attacker.attack >= defender.h_or_d)
	{
		Minion temp;
		std::swap(defender, temp);
	}
	else
	{
		defender.h_or_d -= attacker.attack;
	}

	if (defender.attack >= attacker.h_or_d)
	{
		Minion temp;
		std::swap(attacker, temp);
	}
	else
	{
		attacker.h_or_d -= defender.attack;
	}
}