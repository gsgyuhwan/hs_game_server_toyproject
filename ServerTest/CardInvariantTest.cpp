#include "pch.h"

TEST(DefaultConstructorTest, CardInvariantTest) {
	CardInvariant d=CardInvariant();
	EXPECT_FALSE(d.after_played.has_value());
	EXPECT_FALSE(d.when_played.has_value());
	EXPECT_FALSE(d.when_drawed.has_value());
	EXPECT_FALSE(d.after_drawed.has_value());
	EXPECT_FALSE(d.battlecry.has_value());
	EXPECT_EQ(d.default_cost, 0);
	EXPECT_EQ(d.default_attack, 0);
	EXPECT_EQ(d.default_h_or_d, 0);
	EXPECT_EQ(d.card_tye, CardType::minion);
}

TEST(MinionConstructorTest, CardInvariantTest) {
	function_features_t ff;
	stat_features_t sf;
	sf.default_attack = 1;
	sf.default_h_or_d = 1;
	CardInvariant m = CardInvariant(CardType::minon,ff,sf);
	EXPECT_FALSE(m.after_played.has_value());
	EXPECT_FALSE(m.when_played.has_value());
	EXPECT_FALSE(m.when_drawed.has_value());
	EXPECT_FALSE(m.after_drawed.has_value());
	EXPECT_FALSE(m.battlecry.has_value());
	EXPECT_EQ(m.default_cost, 0);
	EXPECT_EQ(m.default_attack, 1);
	EXPECT_EQ(m.default_h_or_d, 1);
	EXPECT_EQ(m.card_type, CardType::minion);
}

TEST(SpellConstructorTest, CardInvariantTest) {
	function_features_t ff;
	ff.when_played=
		[&](){
		this.GainMana(1);
	}
	stat_features_t sf;
	CardInvariant s = CardInvariant(CardType::minon, ff, sf);
	EXPECT_FALSE(s.after_played.has_value());
	EXPECT_TRUE(s.when_played.has_value());
	EXPECT_FALSE(s.when_drawed.has_value());
	EXPECT_FALSE(s.after_drawed.has_value());
	EXPECT_FALSE(s.battlecry.has_value());
	EXPECT_EQ(s.default_cost, 0);
	EXPECT_EQ(s.default_attack, 0);
	EXPECT_EQ(s.default_h_or_d, 0);
	EXPECT_EQ(s.card_type, CardType::spell);
}

TEST(WeaponConstructorTest, CardInvariantTest) {
	function_features_t ff;
	stat_features_t sf;
	sf.default_attack = 3;
	sf.default_h_or_d = 2;
	CardInvariant m = CardInvariant(CardType::weapon, ff, sf);
	EXPECT_FALSE(m.after_played.has_value());
	EXPECT_FALSE(m.when_played.has_value());
	EXPECT_FALSE(m.when_drawed.has_value());
	EXPECT_FALSE(m.after_drawed.has_value());
	EXPECT_FALSE(m.battlecry.has_value());
	EXPECT_EQ(m.default_cost, 0);
	EXPECT_EQ(m.default_attack, 3);
	EXPECT_EQ(m.default_h_or_d, 2);
	EXPECT_EQ(m.card_type, CardType::weapon);
}

