#include "pch.h"

class SessionTest : public testing::Test {
protected:
	void SetUp() override {
		boost::asio::io_context io_context;
		DummyClient dummy_client(io_context, "127.0.0.1", 8888);
		Session session;
	}
    void TearDown() override {

    }

};

TEST_F(SessionTest, GetReadMoveTest1) {

	Move m{ MoveType::TernaryPlay, FirstParam::MyHand1, SecondParam::MyBoard1, ThirdParam::Face };
	dummy_client.SendMove(m);

	session.ReadMove();
	Move rm = session.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest2) {

	Move m{ MoveType::TernaryPlay, FirstParam::MyHand10, SecondParam::Option1, ThirdParam::MyBoard7};
	dummy_client.SendMove(m);

	session.ReadMove();
	Move rm = session.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest3) {

	Move m{ MoveType::BinaryPlay, FirstParam::Self, SecondParam::Face};
	dummy_client.SendMove(m);

	session.ReadMove();
	Move rm = session.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest4) {

	Move m{ MoveType::BinaryPlay, FirstParam::MyHand1, SecondParam::MyBoard1 };
	dummy_client.SendMove(m);

	session.ReadMove();
	Move rm = session.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest5) {

	Move m{ MoveType::BinaryPlay, FirstParam::MyHand10, SecondParam::Option2 };
	dummy_client.SendMove(m);

	session.ReadMove();
	Move rm = session.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest6) {

	Move m{ MoveType::BinaryPlay, FirstParam::MyHand5, SecondParam::OpBoard7 };
	dummy_client.SendMove(m);

	session.ReadMove();
	Move rm = session.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest7) {

	Move m{ MoveType::UnaryPlay, FirstParam::MyHand3};
	dummy_client.SendMove(m);

	session.ReadMove();
	Move rm = session.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, SendBoardStateTest) {

	BoardState bs{};
	session.SendBoardState(bs);

	EXPECT_EQ(bs, c.ReadBoardState());
}
