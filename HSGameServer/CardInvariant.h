#pragma once
#include <optional>
#include <functional>
#include "Match.h"
#include "CardType.h"
#include "Move.h"


struct function_features_t
{
	std::optional<std::function<void(Match&, Move&)>> when_drawed;
	std::optional<std::function<void(Match&, Move&)>> after_drawed;
	std::optional<std::function<void(Match&, Move&)>> when_played;
	std::optional<std::function<void(Match&, Move&)>> after_played;
	std::optional<std::function<void(Match&, Move&)>> battlecry;
	function_features_t() :
		when_drawed(),
		after_drawed(),
		when_played(),
		after_played(),
		battlecry()
	{}
};

struct stat_features_t
{
	int default_cost;
	int default_attack;
	int default_h_or_d;
	stat_features_t() :
		default_cost(0),
		default_attack(0),
		default_h_or_d(0)
	{}
};

struct CardInvariant
{
	CardType card_type;
	function_features_t function_features;
	stat_features_t stat_features;
};