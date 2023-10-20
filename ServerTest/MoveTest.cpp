#include "pch.h"

TEST(GetMyHandPosTest1, MoveTest) { //MyHand1
	Move m{};
	m.unary_param = UnaryParam::MyHand1;
	EXPECT_EQ(1, m.GetMyHandPos());
}

TEST(GetMyHandPosTest2, MoveTest) { //MyHand7
	Move m{};
	m.unary_param = UnaryParam::MyHand7;
	EXPECT_EQ(7, m.GetMyHandPos());
}

TEST(GetMyBoardPosTest1, MoveTest) { //MyBoard1 with binary param
	Move m{};
	m.binary_param = BinaryParam::MyBoard1;
	EXPECT_EQ(1, m.GetMyBoardPos<BinaryParam>());
}

TEST(GetMyBoardPosTest2, MoveTest) { //MyBoard7 with binary param
	Move m{};
	m.binary_param = BinaryParam::MyBoard7;
	EXPECT_EQ(7, m.GetMyBoardPos<BinaryParam>());
}

TEST(GetMyBoardPosTest3, MoveTest) { //MyBoard1 with ternary param
	Move m{};
	m.ternary_param = TernaryParam::MyBoard1;
	EXPECT_EQ(1, m.GetMyBoardPos<TernaryParam>());
}

TEST(GetMyBoardPosTest4, MoveTest) { //MyBoard7 with ternary param
	Move m{};
	m.ternary_param = TernaryParam::MyBoard7;
	EXPECT_EQ(7, m.GetMyBoardPos<TernaryParam>());
}


TEST(GetOpBoardPosTest1, MoveTest) { //OpBoard1 with binary param
	Move m{};
	m.binary_param = BinaryParam::OpBoard1;
	EXPECT_EQ(1, m.GetOpBoardPos<BinaryParam>());
}

TEST(GetOpBoardPosTest2, MoveTest) { //OpBoard7 with binary param
	Move m{};
	m.binary_param = BinaryParam::OpBoard7;
	EXPECT_EQ(7, m.GetOpBoardPos<BinaryParam>());
}

TEST(GetOpBoardPosTest3, MoveTest) { //OpBoard1 with ternary param
	Move m{};
	m.ternary_param = TernaryParam::OpBoard1;
	EXPECT_EQ(1, m.GetOpBoardPos<TernaryParam>());
}

TEST(GetOpBoardPosTest4, MoveTest) { //OpBoard7 with ternary param
	Move m{};
	m.ternary_param = TernaryParam::OpBoard7;
	EXPECT_EQ(7, m.GetOpBoardPos<TernaryParam>());
}


