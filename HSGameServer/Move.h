#pragma once

enum class MoveType
{
	UnaryPlay,
	BinaryPlay,
	TernaryPlay,
	BinaryAttack,
	HeroPower,
	TurnEnd,
	Surrender,
};

enum class FirstParam
{
	Self,
	MyBoard1 = 1,
	MyBoard2 = 2,
	MyBoard3 = 3,
	MyBoard4 = 4,
	MyBoard5 = 5,
	MyBoard6 = 6,
	MyBoard7 = 7,
	MyHand1 = 1 << 3,
	MyHand2 = 2 << 3,
	MyHand3 = 3 << 3,
	MyHand4 = 4 << 3,
	MyHand5 = 5 << 3,
	MyHand6 = 6 << 3,
	MyHand7 = 7 << 3, 
	MyHand8 = 8 << 3,
	MyHand9 = 9 << 3,
	MyHand10 = 10 << 3,
};

enum class SecondParam
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

enum class ThirdParam
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
	FirstParam first_param;
	SecondParam second_param;
	ThirdParam third_param;

	size_t GetMyHandPos() // assert unary_param's value is MyHand1 ~ MyHand10
	{
		return static_cast<size_t>(first_param) >> 3;
	}

	template <typename T> size_t GetMyBoardPos(){};
	template<> size_t GetMyBoardPos<FirstParam>() // assert binary_param's value is MyBoard1 ~ MyBoard7
	{
		return static_cast<size_t>(first_param);
	}
	template<> size_t GetMyBoardPos<SecondParam>() // assert binary_param's value is MyBoard1 ~ MyBoard7
	{
		return static_cast<size_t>(second_param);
	}
	template<> size_t GetMyBoardPos<ThirdParam>() // assert ternary__param's value is MyBoard1 ~ MyBoard7
	{
		return static_cast<size_t>(third_param);
	}

	template <typename T> size_t GetOpBoardPos() {};
	template<> size_t GetOpBoardPos<SecondParam>() // assert binary_param's value is OpBoard1 ~ OpBoard7
	{
		return static_cast<size_t>(second_param) >> 3;
	}
	template<> size_t GetOpBoardPos<ThirdParam>() // assert ternary__param's value is OpBoard1 ~ OpBoard7
	{
		return static_cast<size_t>(third_param) >> 3;
	}

	template <typename T> bool IsMyBoard() {};
	template<> bool IsMyBoard<FirstParam>() 
	{
		return first_param >= FirstParam::MyBoard1 && first_param <= FirstParam::MyBoard7;
	}
	template<> bool IsMyBoard<SecondParam>() 
	{
		return second_param >= SecondParam::MyBoard1 && second_param <= SecondParam::MyBoard7;
	}

	template <typename T> bool IsMyHand() {};
	template<> bool IsMyHand<FirstParam>() 
	{
		return first_param >= FirstParam::MyHand1 && first_param <= FirstParam::MyHand10;
	}

	template <typename T> bool IsOption() {};
	template<> bool IsOption<SecondParam>() 
	{
		return second_param >= SecondParam::Option1 && second_param <= SecondParam::Option2;
	}
};

