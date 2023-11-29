#include "pch.h"

class MatchTest : public testing::Test {
protected:
	void SetUp() override 
	{

	}
	void TearDown() override 
	{

	}
	boost::asio::io_context io_context1;
	boost::asio::io_context io_context2;
	DummyClient dummy_client1;
	DummyClient dummy_client2;
	Match match;
};



TEST_F(MatchTest, PlayMoveTest) {
	Move m{ MoveType::HeroPower};
	match.PlayMove(m);
	EXPECT_EQ(2, dummy_client1.GetPlayerArmor());
}