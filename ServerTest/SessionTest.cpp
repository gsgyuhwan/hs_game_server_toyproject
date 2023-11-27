#include "pch.h"

class SessionTest : public testing::Test {
protected:
	void SetUp() override {
		boost::asio::io_service io_service;
		DummyClient c(io_service, "127.0.0.1", 8888);
		Session s;
	}
    void TearDown() override {

    }

};

TEST_F(SessionTest, GetReadMoveTest1) {

	Move m{ MoveType::TernaryPlay, FirstParam::MyHand1, SecondParam::MyBoard1, ThirdParam::Face };
	c.SendMove(m);

	s.ReadMove();
	Move rm = s.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest2) {

	Move m{ MoveType::TernaryPlay, FirstParam::MyHand10, SecondParam::Option1, ThirdParam::MyBoard7};
	c.SendMove(m);

	s.ReadMove();
	Move rm = s.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest3) {

	Move m{ MoveType::BinaryPlay, FirstParam::Self, SecondParam::Face};
	c.SendMove(m);

	s.ReadMove();
	Move rm = s.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest4) {

	Move m{ MoveType::BinaryPlay, FirstParam::MyHand1, SecondParam::MyBoard1 };
	c.SendMove(m);

	s.ReadMove();
	Move rm = s.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest5) {

	Move m{ MoveType::BinaryPlay, FirstParam::MyHand10, SecondParam::Option2 };
	c.SendMove(m);

	s.ReadMove();
	Move rm = s.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest6) {

	Move m{ MoveType::BinaryPlay, FirstParam::MyHand5, SecondParam::OpBoard7 };
	c.SendMove(m);

	s.ReadMove();
	Move rm = s.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, GetReadMoveTest7) {

	Move m{ MoveType::UnaryPlay, FirstParam::MyHand3};
	c.SendMove(m);

	s.ReadMove();
	Move rm = s.GetMove();

	EXPECT_EQ(m, rm);
}

TEST_F(SessionTest, SendBoardStateTest) {

	BoardState bs{};
	s.SendBoardState(bs);

	EXPECT_EQ(bs, c.ReadBoardState());
}
