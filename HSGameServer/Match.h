#pragma once
#include <array>
#include <memory>
#include <algorithm>
#include "Board.h"
#include "BoardState.h"
#include "Session.h"
#include "Player.h"
#include "GameServer.h"


class Match : public std::enable_shared_from_this<Match>
{
public:
	Match(std::unique_ptr<Session> session1, std::unique_ptr<Session> session2, std::unordered_set<std::shared_ptr<Match>>& match_set);
	void PlayMove(Move& move);
	
private:
	void StartMatch();
	BoardState GetBoardState();
	void SendAllBoardState();
	void ReadNextMove();
	void UnaryPlay(Move& move);
	void BinaryPlay(Move& move);
	void TernaryPlay(Move& move);
	void MinionAttack(size_t pos1, size_t po2);

	std::array<std::unique_ptr<Session>, 2> sessions_;
	std::array<std::unique_ptr<Board>, 2> boards_;
	std::array<std::unique_ptr<Player>, 2> players_;
	int turn_;
	std::unordered_set<std::shared_ptr<Match>>& match_set_;
};