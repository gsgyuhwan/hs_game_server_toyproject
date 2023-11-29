#pragma once
#include "GameServer.h"

GameServer::GameServer(boost::asio::io_context& io_context, int port):
	acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
	InitializeCardInvariant();
	Accept();
}

CardInstance GameServer::InstantiateCard(CardNumber card_number)
{
	CardInstance card{
		card_number,
		GetDefaultCost(card_number),
		GetDefaultAttack(card_number),
		GetDefaultHealthOrDurability(card_number),
		GetDeathrattle(card_number)
	};
	return card;
}

int GameServer::GetDefaultAttack(CardNumber card_number)
{
	return card_invariants_[card_number].stat_features.default_attack;
}

int GameServer::GetDefaultHealthOrDurability(CardNumber card_number)
{
	return card_invariants_[card_number].stat_features.default_h_or_d;
}

int GameServer::GetDefaultCost(CardNumber card_number)
{
	return card_invariants_[card_number].stat_features.default_cost;
}

std::optional<std::function<void(Match&, Move&)>> GameServer::GetDeathrattle(CardNumber card_number)
{
	return card_invariants_[card_number].function_features.death_rattle;
}

void GameServer::Accept()
{
	acceptor_.async_accept(
		[this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket)
		{
			if (!ec)
			{
				if (waiting_room_.empty())
				{
					waiting_room_.push_back(std::make_unique<Session>(std::move(socket),match_set_));
				}
				else
				{
					match_set_.insert(std::make_shared<Match>(waiting_room_.front(), std::make_unique<Session>(std::move(socket), match_set_)));
					waiting_room_.pop_front();
				}
			}

			Accept();
		});
}

void GameServer::InitializeCardInvariant()
{
	CardType card_type{};
	function_features_t function_features{};
	stat_features_t stat_features{};
	card_invariants_[0] = CardInvariant{ card_type, function_features, stat_features };
}