#pragma once
#include <array>
#include <deque>
#include <set>
#include <optional>
#include <functional>
#include <unordered_set>
#include "CardInstance.h"
#include "CardInvariant.h"
#include "Session.h"
#include "Match.h"

#define MAX_CARD_NUM 15

class GameServer
{
public:
	GameServer(boost::asio::io_context& io_context, int endpoint);
	static CardInstance InstantiateCard(CardNumber card_number);
	static int GetDefaultAttack(CardNumber card_number);
	static int GetDefaultHealthOrDurability(CardNumber card_number);
	static std::optional<std::function<void(Match&, Move&)>> GetDeathrattle(CardNumber card_number);
	static int GetDefaultCost(CardNumber card_number);
private:
	void Accept();
	void InitializeCardInvariant();

	boost::asio::ip::tcp::acceptor acceptor_;
	static std::array<CardInvariant, MAX_CARD_NUM> card_invariants_;
	std::deque<std::unique_ptr<Session>> waiting_room_;
	std::unordered_set<std::shared_ptr<Match>> match_set_;
};