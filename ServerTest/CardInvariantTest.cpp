#include "pch.h"

TEST(DefaultConstructorTest, CardInvariantTest) {
	CardInvariant d = CardInvariant();
	EXPECT_FALSE(d.function_features.after_played.has_value());
	EXPECT_FALSE(d.function_features.when_played.has_value());
	EXPECT_FALSE(d.function_features.when_drawed.has_value());
	EXPECT_FALSE(d.function_features.after_drawed.has_value());
	EXPECT_FALSE(d.function_features.battlecry.has_value());
	EXPECT_EQ(d.stat_features.default_cost, 0);
	EXPECT_EQ(d.stat_features.default_attack, 0);
	EXPECT_EQ(d.stat_features.default_h_or_d, 0);
	EXPECT_EQ(d.card_type, CardType::minion);
}

TEST(MinionConstructorTest, CardInvariantTest) {
	function_features_t ff;
	stat_features_t sf;
	sf.default_attack = 1;
	sf.default_h_or_d = 1;
	CardInvariant m = CardInvariant(CardType::minion,ff,sf);
	EXPECT_FALSE(m.function_features.after_played.has_value());
	EXPECT_FALSE(m.function_features.when_played.has_value());
	EXPECT_FALSE(m.function_features.when_drawed.has_value());
	EXPECT_FALSE(m.function_features.after_drawed.has_value());
	EXPECT_FALSE(m.function_features.battlecry.has_value());
	EXPECT_EQ(m.stat_features.default_cost, 0);
	EXPECT_EQ(m.stat_features.default_attack, 1);
	EXPECT_EQ(m.stat_features.default_h_or_d, 1);
	EXPECT_EQ(m.card_type, CardType::minion);
}

TEST(SpellConstructorTest, CardInvariantTest) {
	function_features_t ff;
	ff.when_played =
		[](Match& match, Move& move) mutable {
	};
	stat_features_t sf;
	CardInvariant s = CardInvariant(CardType::spell, ff, sf);
	EXPECT_FALSE(s.function_features.after_played.has_value());
	EXPECT_TRUE(s.function_features.when_played.has_value());
	EXPECT_FALSE(s.function_features.when_drawed.has_value());
	EXPECT_FALSE(s.function_features.after_drawed.has_value());
	EXPECT_FALSE(s.function_features.battlecry.has_value());
	EXPECT_EQ(s.stat_features.default_cost, 0);
	EXPECT_EQ(s.stat_features.default_attack, 0);
	EXPECT_EQ(s.stat_features.default_h_or_d, 0);
	EXPECT_EQ(s.card_type, CardType::spell);
}

TEST(WeaponConstructorTest, CardInvariantTest) {
	function_features_t ff;
	stat_features_t sf;
	sf.default_attack = 3;
	sf.default_h_or_d = 2;
	CardInvariant w = CardInvariant(CardType::weapon, ff, sf);
	EXPECT_FALSE(w.function_features.after_played.has_value());
	EXPECT_FALSE(w.function_features.when_played.has_value());
	EXPECT_FALSE(w.function_features.when_drawed.has_value());
	EXPECT_FALSE(w.function_features.after_drawed.has_value());
	EXPECT_FALSE(w.function_features.battlecry.has_value());
	EXPECT_EQ(w.stat_features.default_cost, 0);
	EXPECT_EQ(w.stat_features.default_attack, 3);
	EXPECT_EQ(w.stat_features.default_h_or_d, 2);
	EXPECT_EQ(w.card_type, CardType::weapon);
}

