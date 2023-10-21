#pragma once

enum class MoveType
{
	UnaryPlay,
	BinaryPlay,
	TernaryPlay,
	BinaryAttack,
	HeroPower,
	TurnEnd,
};

enum class UnaryParam
{
	Self,
	MyHand1 = 1,
	MyHand2 = 2,
	MyHand3 = 3,
	MyHand4 = 4,
	MyHand5 = 5,
	MyHand6 = 6,
	MyHand7 = 7,
};

enum class BinaryParam
{
	Self,
	Face,
	AllOpBoard,
	MyBoard1 = 1,
	MyBoard2 = 2,
	MyBoard3 = 3,
	MyBoard4 = 4,
	MyBoard5 = 5,
	MyBoard6 = 6,
	MyBoard7 = 7,
	OpBoard1 = 1 << 3,
	OpBoard2 = 2 << 3,
	OpBoard3 = 3 << 3,
	OpBoard4 = 4 << 3,
	OpBoard5 = 5 << 3,
	OpBoard6 = 6 << 3,
	OpBoard7 = 7 << 3,
	Option1,
	Option2,
};

enum class TernaryParam
{
	Self,
	Face,
	AllOpBoard,
	MyBoard1 = 1,
	MyBoard2 = 2,
	MyBoard3 = 3,
	MyBoard4 = 4,
	MyBoard5 = 5,
	MyBoard6 = 6,
	MyBoard7 = 7,
	OpBoard1 = 1 << 3,
	OpBoard2 = 2 << 3,
	OpBoard3 = 3 << 3,
	OpBoard4 = 4 << 3,
	OpBoard5 = 5 << 3,
	OpBoard6 = 6 << 3,
	OpBoard7 = 7 << 3,
};


struct Move 
{
	MoveType move_type;
	UnaryParam unary_param;
	BinaryParam binary_param;
	TernaryParam ternary_param;

	size_t GetMyHandPos() // assert unary_param's value is MyHand1 ~ MyHand7
	{
		return static_cast<size_t>(unary_param);
	}

	template <typename T> size_t GetMyBoardPos(){};
	template<> size_t GetMyBoardPos<BinaryParam>() // assert binary_param's value is MyBoard1 ~ MyBoard7
	{
		return static_cast<size_t>(binary_param);
	}
	template<> size_t GetMyBoardPos<TernaryParam>() // assert ternary__param's value is MyBoard1 ~ MyBoard7
	{
		return static_cast<size_t>(ternary_param);
	}

	template <typename T> size_t GetOpBoardPos() {};
	template<> size_t GetOpBoardPos<BinaryParam>() // assert binary_param's value is OpBoard1 ~ OpBoard7
	{
		return static_cast<size_t>(binary_param) >> 3;
	}
	template<> size_t GetOpBoardPos<TernaryParam>() // assert ternary__param's value is OpBoard1 ~ OpBoard7
	{
		return static_cast<size_t>(ternary_param) >> 3;
	}


};

