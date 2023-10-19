#pragma once

struct CardInstance
{
	uint32_t card_number;
	uint32_t cost;
	uint32_t attack;
	uint32_t h_or_d;
	std::optional<std::function<void(Match&, Move&)>> death_rattle;
};