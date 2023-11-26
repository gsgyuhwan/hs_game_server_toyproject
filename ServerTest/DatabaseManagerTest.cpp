#include "pch.h"

TEST(GetPlayersDeckTest1, DatabaseManagerTest) {
	DatabaseManager m = DatabaseManager::Instance();
	DeckList dl{ 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15, };

	EXPECT_EQ(m.GetPlayersDeck(1), dl);
}

TEST(GetPlayersDeckTest2, DatabaseManagerTest) {
	DatabaseManager m = DatabaseManager::Instance();
	DeckList dl{ 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15, };

	EXPECT_EQ(m.GetPlayersDeck(2), dl);
}