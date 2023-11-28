#include "pch.h"

class MatchTest : public testing::Test {
protected:
	void SetUp() override {
		boost::asio::io_context io_context1;
		DummyClient dummy_client1(io_context1, "127.0.0.1", 8888);
		boost::asio::io_context io_context2;
		DummyClient dummy_client2(io_service2, "127.0.0.1", 8888);
		Match match;
	}
	void TearDown() override {

	}

};

TEST_F(MatchTest, StartMatchTest) {
	match.StartMatch();
	BoardState bs{};
	EXPECT_EQ(bs, dummy_client1.ReadBoardState());
	EXPECT_EQ(bs, dummy_client2.ReadBoardState());
}

TEST_F(MatchTest, EndMatchTest) {
	match.EndMatch();
	EXPECT_FALSE(io_context1.has_service());
	EXPECT_FALSE(io_context2.has_service());
} 

TEST_F(MatchTest, PlayMoveTest) {
	Move m{ MoveType::HeroPower};
	match.PlayMove(m);
	EXPECT_EQ(2, dummy_client1.GetPlayerArmor());
}