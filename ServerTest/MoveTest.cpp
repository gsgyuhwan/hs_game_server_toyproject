#include "pch.h"

TEST(MoveTest, GetMyHandPosTest1) { //MyHand1
	Move m{};
	m.first_param = FirstParam::MyHand1;
	EXPECT_EQ(1, m.GetMyHandPos());
}

TEST(MoveTest, GetMyHandPosTest2) { //MyHand7
	Move m{};
	m.first_param = FirstParam::MyHand10;
	EXPECT_EQ(10, m.GetMyHandPos());
}

TEST(MoveTest, GetMyBoardPosTest1) { //MyBoard1 with second param
	Move m{};
	m.second_param = SecondParam::MyBoard1;
	EXPECT_EQ(1, m.GetMyBoardPos<SecondParam>());
}

TEST(MoveTest, GetMyBoardPosTest2) { //MyBoard7 with second param
	Move m{};
	m.second_param = SecondParam::MyBoard7;
	EXPECT_EQ(7, m.GetMyBoardPos<SecondParam>());
}

TEST(MoveTest, GetMyBoardPosTest3) { //MyBoard1 with third param
	Move m{};
	m.third_param = ThirdParam::MyBoard1;
	EXPECT_EQ(1, m.GetMyBoardPos<ThirdParam>());
}

TEST(MoveTest, GetMyBoardPosTest4) { //MyBoard7 with third param
	Move m{};
	m.third_param = ThirdParam::MyBoard7;
	EXPECT_EQ(7, m.GetMyBoardPos<ThirdParam>());
}

TEST(MoveTest, GetMyBoardPosTest5) { //MyBoard1 with first param
	Move m{};
	m.first_param = FirstParam::MyBoard1;
	EXPECT_EQ(1, m.GetMyBoardPos<FirstParam>());
}

TEST(MoveTest, GetMyBoardPosTest6) { //MyBoard7 with first param
	Move m{};
	m.first_param = FirstParam::MyBoard7;
	EXPECT_EQ(7, m.GetMyBoardPos<FirstParam>());
}


TEST(MoveTest, GetOpBoardPosTest1) { //OpBoard1 with binary param
	Move m{};
	m.second_param = SecondParam::OpBoard1;
	EXPECT_EQ(1, m.GetOpBoardPos<SecondParam>());
}

TEST(MoveTest, GetOpBoardPosTest2) { //OpBoard7 with binary param
	Move m{};
	m.second_param = SecondParam::OpBoard7;
	EXPECT_EQ(7, m.GetOpBoardPos<SecondParam>());
}

TEST(MoveTest, GetOpBoardPosTest3) { //OpBoard1 with ternary param
	Move m{};
	m.third_param = ThirdParam::OpBoard1;
	EXPECT_EQ(1, m.GetOpBoardPos<ThirdParam>());
}

TEST(MoveTest, GetOpBoardPosTest4) { //OpBoard7 with ternary param
	Move m{};
	m.third_param = ThirdParam::OpBoard7;
	EXPECT_EQ(7, m.GetOpBoardPos<ThirdParam>());
}


