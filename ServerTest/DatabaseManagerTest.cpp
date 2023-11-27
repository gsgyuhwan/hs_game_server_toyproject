#include "pch.h"

TEST(DatabaseManagerTest, GetPlayersDeckTest1) {
	DeckList dl{ 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15, };

	EXPECT_EQ(DatabaseManager::Instance().GetPlayersDeck(1), dl);
}

TEST(DatabaseManagerTest, GetPlayersDeckTest2) {
	DeckList dl{ 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15, };

	EXPECT_EQ(DatabaseManager::Instance().GetPlayersDeck(2), dl);
}

