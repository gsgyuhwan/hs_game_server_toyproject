#include "pch.h"

TEST(CardInstanceTest, DefaultConstructorTest) {
	CardInstance c = CardInstance();
	EXPECT_FALSE(c.death_rattle.has_value());
	EXPECT_EQ(c.card_number, 0);
	EXPECT_EQ(c.cost, 0);
	EXPECT_EQ(c.attack, 0);
}