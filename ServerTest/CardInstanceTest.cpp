#include "pch.h"

TEST(DefaultConstructorTest, CardInstanceTest) {
	CardInstance c = CardInstance();
	EXPECT_FALSE(c.deathrattle.has_value());
	EXPECT_EQ(c.card_number, 0);
	EXPECT_EQ(c.cost, 0);
	EXPECT_EQ(c.attack, 0);
}