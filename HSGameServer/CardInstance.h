#pragma once
#include "AliasedTypes.h"

struct CardInstance
{
	CardNumber card_number;
	int cost;
	int attack;
	int h_or_d;
	std::optional<std::function<void(Match&, Move&)>> death_rattle;
};