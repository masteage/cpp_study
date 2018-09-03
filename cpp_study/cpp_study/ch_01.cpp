//
//  ch_01.cpp
//  cpp_study
//
//  Created by taeseongsong on 2018. 9. 2..
//  Copyright © 2018년 taeseongsong. All rights reserved.
//

#include "ch_01.hpp"

#pragma mark - declare
void literal();
void data_type();
void enumeration();
void std_arry();
void void_param_func(void);
void predefined_macros();
auto add_two(int i) -> int;
auto divide_numbers(double numerator, double denominator);
void alternative_function();

#pragma mark - main
void ch_01_main()
{
	literal();
	data_type();
	enumeration();
	std_arry();
	void_param_func();
	predefined_macros();
	alternative_function();
}

#pragma mark - definition
void literal()
{
//	int number1 = 23'456'789;
	int number1 = 2'3'4'5'6'7'8'9;
//	float number2 = 0.123'456f;
	float number2 = 0.1'2'3'4'5'6f;
	int nBinary = 0b011;
	
	cout << "number1 : " << number1 << endl;
	cout << "number2 : " << number2 << endl;
	cout << "nBinary : " << nBinary << endl;
}

void data_type()
{
	int someInteger = 256;
	short someShort;
	long someLong;
	float someFloat;
	double someDouble;
	
	someInteger++;
	someInteger *= 2;
	someShort = static_cast<short>(someInteger);
	someLong = someShort * 10000;
	
	// 5140000 + 0.785.f -> 5140001 (부동 소수점이지만 크기가 커서 소수점 표기 불가) (7digits)
	someFloat = someLong + 0.785f;
	
	// 5140000.7850000262 - 아마도 이 값을 원했을지도?
	someDouble = static_cast<double>(someLong) + static_cast<double>(0.785f);
	someDouble = static_cast<double>(someFloat) / 100000;
	
	cout << someDouble << endl;
}


void enumeration()
{
	// enum type
	enum PieceType {PieceTypeKing = 1, PieceTypeQueen, PieceTypeRook = 10, PieceTypePawn};
	enum PieceTypeOther {PieceTypeOtherKing = 100, PieceTypeOtherQueen, PieceTypeOtherRook = 1200, PieceTypeOtherPawn};
	
	PieceType tmpPieceType = PieceTypeKing;
	tmpPieceType = (PieceType)13;	// not good
	tmpPieceType = PieceTypeRook;	// good
	
	PieceTypeOther tmpPieceTypeOther = PieceTypeOtherKing;
	tmpPieceTypeOther = (PieceTypeOther)tmpPieceType;	// not good
	tmpPieceTypeOther = PieceTypeOtherKing;
	
	
	// enum class
	enum class MyEnum
	{
		EnumValue1 = -1,
		EnumValue2 = 10,
		EnumValue3
	};
	
	enum class MyEnumLong : unsigned long
	{
		EnumValueLong1,
//		EnumValueLong1 = -1,	// compile error
		EnumValueLong2 = 10,
		EnumValueLong3
	};
	
	MyEnum tmpMyEnum = MyEnum::EnumValue1;
	tmpMyEnum = (MyEnum)100;			// not good
	tmpMyEnum = MyEnum::EnumValue2;		// good
//	if(MyEnum::EnumValue2 == 10)		// compile error
	if(tmpMyEnum == MyEnum::EnumValue2)
	{
		cout << "tmpMyEnum == MyEnum::EnumValue2" << endl;
	}
}

void std_arry()
{
//	#include <array>
	array<int, 3> arr = { 9, 8, 7 };
	cout << "Array size = " << arr.size() << endl;
	arr[1] = 999;
	cout << "Element 2 = " << arr[1] << endl;
	
	// not good
	arr[3] = 888;
	cout << "Element 4 = " << arr[3] << endl;
	arr[4] = 777;
	cout << "Element 5 = " << arr[4] << endl;
	cout << "Array size = " << arr.size() << endl;	// 3
	
	
	// arr print
	array<int, 4> arr2 = {1,2,3,4};
	for(int i : arr2) {
		cout << i <<endl;
	}
}

void void_param_func(void)
{
	cout << "c 에서는 parameter 가 비었을경우 void 라고 써줘야함." <<endl;
}

void predefined_macros()
{
//	https://msdn.microsoft.com/ko-kr/library/b0084kay(v=vs.120).aspx
	cout << "__func__ : " << __func__ <<endl;
	cout << "__FUNCTION__ : " << __FUNCTION__ <<endl;
	cout << "__DATE__ : " << __DATE__ <<endl;
	cout << "__FILE__ : " << __FILE__ <<endl;
	cout << "__LINE__ : " << __LINE__ <<endl;
	cout << "__STDC__ : " << __STDC__ <<endl;
	cout << "__TIME__ : " << __TIME__ <<endl;
	cout << "__TIMESTAMP__ : " << __TIMESTAMP__ <<endl;
}

auto add_two(int i) -> int
{
	return i+2;
}

auto divide_numbers(double numerator, double denominator)
{
//	if(denominator == 0){return false;}		// fail - other type
//	if(denominator == 0){return 0;}			// fail - other type
	if(denominator == 0){return (double)0;}	// success
//	if(denominator == 0){/**/}
	return numerator / denominator;
}

void alternative_function()
{
	cout << "add_two(5) : " << add_two(5) << endl;
	cout << "divide_numbers(3, 4) : " << divide_numbers(3, 4) << endl;
	cout << "divide_numbers(0, 4) : " << divide_numbers(0, 4) << endl;
	cout << "divide_numbers(3, 0) : " << divide_numbers(3, 0) << endl;
}



