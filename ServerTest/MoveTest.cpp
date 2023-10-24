#include "pch.h"

TEST(GetMyHandPosTest1, MoveTest) { //MyHand1
	Move m{};
	m.first_param = FirstParam::MyHand1;
	EXPECT_EQ(1, m.GetMyHandPos());
}

TEST(GetMyHandPosTest2, MoveTest) { //MyHand7
	Move m{};
	m.first_param = FirstParam::MyHand10;
	EXPECT_EQ(10, m.GetMyHandPos());
}

TEST(GetMyBoardPosTest1, MoveTest) { //MyBoard1 with second param
	Move m{};
	m.second_param = SecondParam::MyBoard1;
	EXPECT_EQ(1, m.GetMyBoardPos<SecondParam>());
}

TEST(GetMyBoardPosTest2, MoveTest) { //MyBoard7 with second param
	Move m{};
	m.second_param = SecondParam::MyBoard7;
	EXPECT_EQ(7, m.GetMyBoardPos<SecondParam>());
}

TEST(GetMyBoardPosTest3, MoveTest) { //MyBoard1 with third param
	Move m{};
	m.third_param = ThirdParam::MyBoard1;
	EXPECT_EQ(1, m.GetMyBoardPos<ThirdParam>());
}

TEST(GetMyBoardPosTest4, MoveTest) { //MyBoard7 with third param
	Move m{};
	m.third_param = ThirdParam::MyBoard7;
	EXPECT_EQ(7, m.GetMyBoardPos<ThirdParam>());
}

TEST(GetMyBoardPosTest5, MoveTest) { //MyBoard1 with first param
	Move m{};
	m.first_param = FirstParam::MyBoard1;
	EXPECT_EQ(1, m.GetMyBoardPos<FirstParam>());
}

TEST(GetMyBoardPosTest6, MoveTest) { //MyBoard7 with first param
	Move m{};
	m.first_param = FirstParam::MyBoard7;
	EXPECT_EQ(7, m.GetMyBoardPos<FirstParam>());
}


TEST(GetOpBoardPosTest1, MoveTest) { //OpBoard1 with binary param
	Move m{};
	m.second_param = SecondParam::OpBoard1;
	EXPECT_EQ(1, m.GetOpBoardPos<SecondParam>());
}

TEST(GetOpBoardPosTest2, MoveTest) { //OpBoard7 with binary param
	Move m{};
	m.second_param = SecondParam::OpBoard7;
	EXPECT_EQ(7, m.GetOpBoardPos<SecondParam>());
}

TEST(GetOpBoardPosTest3, MoveTest) { //OpBoard1 with ternary param
	Move m{};
	m.third_param = ThirdParam::OpBoard1;
	EXPECT_EQ(1, m.GetOpBoardPos<ThirdParam>());
}

TEST(GetOpBoardPosTest4, MoveTest) { //OpBoard7 with ternary param
	Move m{};
	m.third_param = ThirdParam::OpBoard7;
	EXPECT_EQ(7, m.GetOpBoardPos<ThirdParam>());
}


