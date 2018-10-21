//
//  ch_10.cpp
//  cpp_study
//
//  Created by taeseongsong on 21/10/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "ch_10.hpp"

void ch_10_1_1(){
	
	cout << "-------------" << endl;
	int x = 3;
	int &xRef = x;
	xRef = 10;
	cout << "xRef : " << xRef << endl;
	
	// Non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
//	int& unnamedRef1 = 5;
	const int& unnamedRef2 = 5;
	cout << "unnamedRef2 : " << unnamedRef2 << endl;
	
	cout << "-------------" << endl;
}

void ch_10_1_1_1(){
	
	cout << "-------------" << endl;
	
	int x = 3, y = 4, z = 5;
	int &xRef = x;	// &xRef = x
	int &zRef = z;	// &xRef = x
	xRef = y;		// xRef = 4 , x = 4
	cout << "xRef : " << xRef << endl;
	cout << "x : " << x << endl;
	
	cout << "-------------" << endl;
	
	// Assigning to 'int' from incompatible type 'int *'; remove &
//	xRef = &y;
	
	x = 3;
	cout << "x : " << x << endl;			// 3
	cout << "z : " << z << endl;			// 5
	cout << "xRef : " << xRef << endl;		// 3
	cout << "zRef : " << zRef << endl;		// 5
	zRef = xRef;
	cout << "x : " << x << endl;			// 3
	cout << "z : " << z << endl;			// 3
	cout << "xRef : " << xRef << endl;		// 3
	cout << "zRef : " << zRef << endl;		// 3
	
	cout << "-------------" << endl;
}

void ch_10_1_1_2(){
	cout << "-------------" << endl;
	int* intP;
	int*& ptrRef = intP;	// int pointer reference value
	cout << "intP : " << intP << endl;
	cout << "ptrRef : " << ptrRef << endl;
	cout << "*intP : " << *intP << endl;
	cout << "*ptrRef : " << *ptrRef << endl;
	ptrRef = new int;
	cout << "intP : " << intP << endl;
	cout << "ptrRef : " << ptrRef << endl;
	cout << "*intP : " << *intP << endl;
	cout << "*ptrRef : " << *ptrRef << endl;
	*ptrRef = 5;
	cout << "intP : " << intP << endl;
	cout << "ptrRef : " << ptrRef << endl;
	cout << "*intP : " << *intP << endl;
	cout << "*ptrRef : " << *ptrRef << endl;
	cout << "-------------" << endl;
	
	
	int x = 3;
	int& xRef = x;
	int* xPtr = &xRef;
	*xPtr = 100;
	
	cout << "x : " << x << endl;
	cout << "&x : " << &x << endl;
	cout << "xRef : " << xRef << endl;
	cout << "&xRef : " << &xRef << endl;
	cout << "*xPtr : " << *xPtr << endl;
	cout << "xPtr : " << xPtr << endl;
	cout << "-------------" << endl;
	
//	int&& xRefRef = xRef;
//	int&* xRefPtr;
}

void ch_10_1_2(){
	class MyClass{
	public:
		MyClass(int &ref) : mRef(ref){}
	private:
		int& mRef;
	};

	int n = 10;
	MyClass c(n);
}

void swap(int& first, int& second){
	int temp = first;
	first = second;
	second = temp;
}

void swap_ptr(int* first, int* second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void ch_10_1_3(){
	int x = 10,y = 20;
	swap(x,y);
//	swap(1,2);
	
	int *xp = &x, *yp = &y;
//	swap(xp,yp);	// another call
	swap(*xp,*yp);
	cout << "" << endl;
}

void separateOddsAndEvens_ptr(const int arr[], int size, int** odds, int* numOdds, int** evens, int* numEvens)
{
	*numOdds = *numEvens = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			++(*numOdds);
		} else {
			++(*numEvens);
		}
	}
	
	*odds = new int[*numOdds];
	*evens = new int[*numEvens];
	
	int oddsPos = 0, evensPos = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			(*odds)[oddsPos++] = arr[i];
		} else {
			(*evens)[evensPos++] = arr[i];
		}
	}
}

void separateOddsAndEvens_ref(const int arr[], int size, int*& odds, int& numOdds, int*& evens, int& numEvens)
{
	numOdds = numEvens = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			++numOdds;
		} else {
			++numEvens;
		}
	}
	
	odds = new int[numOdds];
	evens = new int[numEvens];
	
	int oddsPos = 0, evensPos = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			odds[oddsPos++] = arr[i];
		} else {
			evens[evensPos++] = arr[i];
		}
	}
}

void separateOddsAndEvens(const vector<int>& arr, vector<int>& odds, vector<int>& evens)
{
	int numOdds = 0, numEvens = 0;
	for (auto& i : arr) {
		if (i % 2 == 1) {
			++numOdds;
		} else {
			++numEvens;
		}
	}
	
	odds.reserve(numOdds);
	evens.reserve(numEvens);
	
	for (auto& i : arr) {
		if (i % 2 == 1) {
			odds.push_back(i);
		} else {
			evens.push_back(i);
		}
	}
}

void recall(int& t){++t;}
void ch_10_1_5(){
	
	// bad acess
//	int* ptr = nullptr;
	
	int y = 10;
	int* ptr = &y;
	recall(*ptr);
	
	int x = 10;
	int& ref = x;
	cout << "x : " << x << endl;
	recall(ref);
	cout << "x : " << x << endl;
	
	// ptr
	int unSplit_ptr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *oddNums_ptr, *evenNums_ptr;
	int numOdds_ptr, numEvens_ptr;
	separateOddsAndEvens_ptr(unSplit_ptr, 10, &oddNums_ptr, &numOdds_ptr, &evenNums_ptr, &numEvens_ptr);
	
	// ref
	int unSplit_ref[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *oddNums_ref, *evenNums_ref;
	int numOdds_ref, numEvens_ref;
	separateOddsAndEvens_ref(unSplit_ref, 10, oddNums_ref, numOdds_ref, evenNums_ref, numEvens_ref);
	
	// stl
	vector<int> vecUnSplit = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> odds, evens;
	separateOddsAndEvens(vecUnSplit, odds, evens);
}

void incr(int& value){
	cout << "[L] increment with lvalue reference" << endl;
	++value;
}

void incr(int&& value){
	cout << "[R] increment with rvalue reference" << endl;
	++value;
}

void ch_10_1_6(){
	int a = 10, b = 20;
	
	// 기본 (좌)
	incr(a);
	cout << "  a=" << a << ", b=" << b << endl;
	
	// 임시 객체 (우)
	incr(a + b);
	cout << "  a=" << a << ", b=" << b << endl;
	
	// 상수 (우)
	incr(3);
	cout << "  a=" << a << ", b=" << b << endl;
	
	// rvalue reference return (우)
	incr(std::move(b));
	cout << "  a=" << a << ", b=" << b << endl;
	
	
	// Non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
//	int& i = 2;
	int&& i = 2;	// 함수 범위 넘어가면 없어짐
	int c = 2, d = 3;
	i = 10;
	
	// Non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
//	int& j = c + d;
	int&& j = c + d;	// 함수 범위 넘어가면 없어짐
	cout << "" << endl;
	j = 10;
}

#include "Spreadsheet.h"
Spreadsheet CreateObject(){
	return Spreadsheet(3, 2);
}

void ch_10_1_6_1(){
	vector<Spreadsheet> vec;
	for (int i = 0; i < 2; ++i) {
		cout << "Iteration " << i << endl;
		vec.push_back(Spreadsheet(100, 100));
		cout << endl;
	}
	
	Spreadsheet s(2,3);
	s = CreateObject();
	
	Spreadsheet s2(5,6);
	s2 = s;
	
	
	// move 가 없을경우 copy 호출됨.
}

const int getArraySize(){return 32;}
constexpr int getArraySize_02(){return 32;}
void ch_10_2_1_2(){
	int myArray[getArraySize()+1];
	int myArray_02[getArraySize_02()+1];
	myArray[0] = 10;
	myArray_02[0] = 10;
	cout << "myArray[0] : " << myArray[0] << endl;
	cout << "myArray_02[0] : " << myArray_02[0] << endl;
}

void f();
extern int extern_x;
extern int extern_y;
void ch_10_2_2_1(){
//	f();
//	cout << "extern_x : " << extern_x << endl;
//	cout << "extern_y : " << extern_y << endl;
	cout << "-------------" << endl;
}

typedef int (*FuncType)(char,double);
using FuncType_02 = int(*)(char,double);
int myTmpFunc(char c, double d){
	cout << "c : " << c << endl;
	cout << "d : " << d << endl;
	return 0;
}

void ch_10_3_3(){
	FuncType aa = myTmpFunc;
	FuncType_02 bb = myTmpFunc;
	aa('a',10);
	bb('b',20);
	cout << "-------------" << endl;
}

void ch_10_3_4(){
	class X {};
	class Y {};
	X* tmpX;
	Y* tmpY;
//	tmpY = reinterpret_cast<Y*>(tmpX);
	
	// Static_cast from 'X *' to 'Y *', which are not related by inheritance, is not allowed
//	tmpY = static_cast<Y*>(tmpX);
	
	tmpX = nullptr;
	tmpY = nullptr;
	
	
	class Base{
	public:
		Base() {}
		virtual ~Base() {}
		void somthing(){};
	};
	
	class Derived : public Base{
	public:
		Derived() {}
		virtual ~Derived() {}
	};
	
	Base* b;
	Derived* d = new Derived();
	b = d;
	d = dynamic_cast<Derived*>(b);
	
	
//	Base* b = new Base();
//	Derived* d;
//	d = dynamic_cast<Derived*>(b);	// null
	
	
//	Base base;
//	Derived derived;
//	Base& br = base;
//	try {
//		Derived& dr = dynamic_cast<Derived&>(br);
//		dr.somthing();
//	} catch (const bad_cast&) {
//		cout << "Bad cast!\n";
//	}
}

struct CircleStruct{
	int x, y;
	double radius;
};

class CircleClass{
public:
	CircleClass(int x, int y, double radius)
	: mX(x), mY(y), mRadius(radius) {}
private:
	int mX, mY;
	double mRadius;
};

void func(int i) { /* ... */ }

class MyClass{
public:
	MyClass() : mArray{0, 1, 2, 3}{};
//	{for(int i = 0 ; i < 4 ; i++){cout<< mArray[i] <<endl;}};;;
private:
	int mArray[4];
};

void ch_10_5_1(){
	
	// old
	CircleStruct myCircle1 = {10, 10, 2.5};
	CircleClass myCircle2(10, 10, 2.5);
	
	// uniform initialization
	CircleStruct myCircle3 = {10, 10, 2.5};
	CircleClass myCircle4 = {10, 10, 2.5};
	CircleStruct myCircle5{10, 10, 2.5};
	CircleClass myCircle6{10, 10, 2.5};
	
	int a = 3;
	int b(3);
	int c = { 3 }; // Uniform initialization
	int d{ 3 }; // Uniform initialization
	
	// Narrowing
	int x = 3.14;
	func(3.14);
	
	// Preventing narrowing
//	int x2 = {3.14};	// Type 'double' cannot be narrowed to 'int' in initializer list
//	func({3.14});	// Type 'double' cannot be narrowed to 'int' in initializer list
	int x3 = {3};
	func({3});
	
	// Uniform initialization also works with vectors and maps
	vector<string> myVec = {"String 1", "String 2", "String 3"};
	
	// Uniform initialization can also be used with dynamically allocated arrays
	int* pArray = new int[4]{0, 1, 2, 3};
	for(int i = 0 ; i < 4 ; i++){
		cout<< pArray[i] <<endl;
	}
	
	// Create a MyClass object
	MyClass myClass;
}

int makeSum(initializer_list<int> lst){
	int total = 0;
	for (const auto& value : lst) {
		total += value;
	}
	return total;
}

void ch_10_5_2(){
	cout << makeSum({ 1, 2, 3 }) << endl;
//	cout << makeSum({ 1, 2, 3.0 }) << endl;
}

void ch_10_5_3(){
	class IntWrapper{
	public:
		IntWrapper(int i) : mInt(i) {}
//		operator int() const { return mInt; }
		explicit operator int() const { return mInt; }
	private:
		int mInt;
	};
	
	IntWrapper c(123);
	
//	int iC1 = c;
//	cout << "iC1=" << iC1 << endl;
	
	int iC2 = static_cast<int>(c);
	cout << "iC2=" << iC2 << endl;
	
}


//https://en.cppreference.com/w/cpp/language/attributes/noreturn
//[[ noreturn ]] void f() {
//	throw "error";
//	// OK
//}

#include <complex>
std::complex<double> operator"" _i(long double d){
	return std::complex<double>(0, d);
}

double operator"" _my(long double d){
	return d*2.f;
}

std::string operator"" _s(const char* str, size_t len){
	return std::string(str, len);
}

void ch_10_5_5(){
	// _i
	std::complex<double> c1 = 9.634_i;
	auto c2 = 1.23_i;
	
	// _my
	double c3 = 3.14_my;
	
	// _s
	std::string str1 = "Hello World"_s;
	auto str2 = "Hello World"_s;   // str2 will have as type std::string
	auto str3 = "Hello World";     // str3 will have as type const char*
	
	auto myString = "Heee"s;
	auto myTime = 40min;
	auto myComplexNumber = 3.14i;
	cout << "-------------" << endl;
}

bool debug = true;
void debugOut(const char* str, ...){
	if (debug){
		va_list ap;
		va_start(ap, str);
		vfprintf(stderr, str, ap);
		va_end(ap);
	}
}

void printInts(int paramCount, ...){
	int temp;
	va_list ap;
	va_start(ap, paramCount);
	for (int i = 0; i < paramCount; ++i) {
		temp = va_arg(ap, int);
		cout << temp << " ";
	}
	va_end(ap);
	cout << endl;
}

int mySum(int paramCount, ...){
	int sum = 0;
	va_list ap;
	va_start(ap, paramCount);
	for (int i = 0; i < paramCount; ++i) {
//		int tmp = va_arg(ap, int);
//		sum += tmp;
		sum += va_arg(ap, int);
	}
	return sum;
}

void ch_10_7(){
	debugOut("int %d\n", 5);
	debugOut("String %s and int %d\n", "hello", 5);
	debugOut("Many ints: %d, %d, %d, %d, %d\n", 1, 2, 3, 4, 5);
	printInts(5, 5, 4, 3, 2, 1);
	cout<< "mySum : " << mySum(5, 5, 4, 3, 2, 1) << endl;
//	cout<< "mySum : " << mySum(5, 5, 4, 3.1, 2, 1) << endl;
}

//#define SQUARE(x) (x * x)		// 2 + 3 * 2 + 3 = 11
#define SQUARE(x) ((x) * (x))	// (2+3) * (2+3)

int veryExpensiveFunction(){
	cout << "veryExpensiveFunction call" << endl;
	return 2+3;
}

void ch_10_7_2(){
	cout << SQUARE(5) << endl;
	cout << SQUARE(2 + 3) << endl;
	cout << SQUARE(veryExpensiveFunction()) << endl;
	cout << "-------------" << endl;
}

void ch_10_main(){
	ch_10_1_1();
	ch_10_1_1_1();
	ch_10_1_1_2();
	ch_10_1_2();
	ch_10_1_3();
	ch_10_1_5();
	ch_10_1_6();
	ch_10_1_6_1();
	ch_10_2_1_2();
	ch_10_2_2_1();
	ch_10_3_3();
	ch_10_5_1();
	ch_10_5_2();
	ch_10_5_3();
	ch_10_5_5();
	ch_10_7();
	ch_10_7_2();
	cout << "" << endl;
}
