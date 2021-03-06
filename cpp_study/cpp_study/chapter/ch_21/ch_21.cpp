//
//  ch_21.cpp
//  ch_21
//
//  Created by taeseongsong on 21/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#include "ch_21.hpp"

#include <deque>
#include "Grid.h"
void ch_21_1_1(){
#ifdef	_TEMPLATE_NORMAL_
	Grid<int, vector<int>> myIntVectorGrid;
	Grid<int, deque<int>> myIntDequeGrid;
	
	myIntVectorGrid.setElementAt(3, 4, 5);
	cout << myIntVectorGrid.getElementAt(3, 4) << endl;
	
	myIntDequeGrid.setElementAt(1, 2, 3);
	cout << myIntDequeGrid.getElementAt(1, 2) << endl;
	
	Grid<int, vector<int>> grid2(myIntVectorGrid);
	grid2 = myIntVectorGrid;
	cout << grid2.getElementAt(3, 4) << endl;
	
	// compile error
//	Grid<int, int> test;
#endif	// _TEMPLATE_NORMAL_
}

void ch_21_1_1_1(){
#ifdef _DEFAULT_TEMPLATE_TYPE_
	Grid<int, deque<int>> myDequeGrid;
	Grid<int, vector<int>> myVectorGrid;
	Grid<int> myVectorGrid_01;					// Grid<int, vector<int>>
	Grid<float> myVectorGrid_02;				// Grid<float, vector<float>>
	Grid<int, deque<float>> myDequeGrid_01;		// Grid<int, deque<float>> - logical bug
#endif	// _DEFAULT_TEMPLATE_TYPE_
}

void ch_21_1_2(){
#ifdef _TEMPLATE_TEMPLATE_PARAMETER_
	Grid<int, vector> myGrid;					// Grid<int, vector<int>>
	myGrid.setElementAt(1, 2, 3);
	cout << myGrid.getElementAt(1, 2) << endl;
	Grid<int, vector> myGrid2(myGrid);			// Grid<int, vector<int>>
	Grid<int> myGrid3(myGrid2);					// Grid<int, vector<int>>
	
	// Template argument for template template parameter must be a class template or type alias template
//	Grid<int, vector<int>> myGrid3;
	
	
	// https://en.cppreference.com/w/cpp/memory/allocator
#endif	// _TEMPLATE_TEMPLATE_PARAMETER_
}

#include "SpreadsheetCell.hpp"
void ch_21_1_3(){
#ifdef _NON_TYPE_TEMPLATE_PARAMETER_
	Grid<int> myIntGrid;		// Initial value is 0
	Grid<int, 10> myIntGrid2;	// Initial value is 10
	
	// A non-type template parameter cannot have type 'SpreadsheetCell'
//	SpreadsheetCell defaultCell;
//	Grid<SpreadsheetCell, defaultCell> mySpreadsheet;
	
	// A non-type template parameter cannot have type 'float'
//	Grid<float, 10.0> myFloatGrid;
	
#endif	// _NON_TYPE_TEMPLATE_PARAMETER_
}

namespace {
//	const int defaultInt = 11;
//	const SpreadsheetCell defaultCell(1.2);
	int defaultInt = 11;
	SpreadsheetCell defaultCell(1.2);
}

SpreadsheetCell defaultCellTmp(1.2);
//const SpreadsheetCell defaultCellTmp(1.2);

void ch_21_1_3_1(){
#ifdef _NON_TYPE_TEMPLATE_PARAMETER_REF_
	Grid<int, defaultInt> myIntGrid;
	Grid<SpreadsheetCell, defaultCell> mySpreadsheet;
	Grid<int, defaultInt> myIntGrid2(myIntGrid);
	
	// Non-type template argument does not refer to any declaration
//	Grid<int, 11> myIntGrid3;
	
	// Non-type template argument refers to object 'defaultCell' that does not have linkage
//	SpreadsheetCell defaultCellTmp;
//	Grid<int, defaultCellTmp> mySpreadsheet1;
	
//	static const SpreadsheetCell defaultCellTmp(1.2);
	Grid<SpreadsheetCell, defaultCellTmp> mySpreadsheet2;
#endif	// _NON_TYPE_TEMPLATE_PARAMETER_REF_
}

template <typename T, size_t WIDTH, size_t HEIGHT>
class Grid_Partial{
public:
	Grid_Partial();
private:
	T mCells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
Grid_Partial<T, WIDTH, HEIGHT>::Grid_Partial() : mCells(){}

// partial class specialization
template <size_t WIDTH, size_t HEIGHT>
class Grid_Partial<const char*, WIDTH, HEIGHT>{
public:
	Grid_Partial();
private:
	std::string mCells[WIDTH][HEIGHT];
};

template <size_t WIDTH, size_t HEIGHT>
Grid_Partial<const char*, WIDTH, HEIGHT>::Grid_Partial() : mCells(){}

void ch_21_2(){
	Grid_Partial<int, 10, 10> myGrid;
	Grid_Partial<int, 10, 10> anotherGrid;
	Grid_Partial<int, 2, 2> myIntGrid;				// Uses the original Grid
	Grid_Partial<const char*, 2, 2> myStringGrid;	// Uses the partial specialization
//	Grid_Partial<2, 3> test;
//	myIntGrid = myStringGrid;
}

#include "Grid_Ptr.h"
void ch_21_2_1(){
	Grid_Ptr<int> myIntGrid;     // Uses the non-specialized grid
	Grid_Ptr<int*> psGrid(2, 2); // Uses the partial specialization for pointer types

	psGrid.setElementAt(0, 0, make_unique<int>(1));
	psGrid.setElementAt(0, 1, make_unique<int>(2));
	psGrid.setElementAt(1, 0, make_unique<int>(3));

	Grid_Ptr<int*> psGrid2(psGrid);
	Grid_Ptr<int*> psGrid3;
	psGrid3 = psGrid2;

	auto element = psGrid2.getElementAt(1, 0);
	if (element) {
		cout << *element << endl;
		*element = 6;
	}
	cout << *psGrid.getElementAt(1, 0) << endl;  // psGrid is not modified
	cout << *psGrid2.getElementAt(1, 0) << endl; // psGrid2 is modified
}

static const size_t NOT_FOUND = (size_t)(-1);

template <typename T>
size_t Find(T& value, T* arr, size_t size)
{
	cout << "original" << endl;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i; // found it; return the index
		}
	}
	return NOT_FOUND; // failed to find it; return NOT_FOUND
}

template <typename T>
size_t Find(T*& value, T** arr, size_t size)
{
	cout << "ptr special" << endl;
	for (size_t i = 0; i < size; i++) {
		if (*arr[i] == *value) {
			return i; // found it; return the index
		}
	}
	return NOT_FOUND; // failed to find it; return NOT_FOUND
}

// This does not work.
//template <typename T>
//size_t Find<T*>(T*& value, T** arr, size_t size)
//{
//	cout << "ptr special" << endl;
//	for (size_t i = 0; i < size; i++) {
//		if (*arr[i] == *value) {
//			return i; // found it; return the index
//		}
//	}
//	return NOT_FOUND; // failed to find it; return NOT_FOUND
//}

template<>
size_t Find<const char*>(const char*& value, const char** arr, size_t size)
{
	cout << "Specialization" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // found it; return the index
		}
	}
	return NOT_FOUND; // failed to find it; return NOT_FOUND
}

size_t Find(const char*& value, const char** arr, size_t size)
{
	cout << "overload" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // found it; return the index
		}
	}
	return NOT_FOUND; // failed to find it; return NOT_FOUND
}

void ch_21_3(){
	size_t res = NOT_FOUND;
	
	int x = 3, intArr[] = { 1, 2, 3, 4 };
	size_t sizeArr = sizeof(intArr) / sizeof(int);
	res = Find(x, intArr, sizeArr);      // calls Find<int> by deduction
	res = Find<int>(x, intArr, sizeArr); // calls Find<int> explicitly
	
	double d1 = 5.6, dArr[] = { 1.2, 3.4, 5.7, 7.5 };
	sizeArr = sizeof(dArr) / sizeof(double);
	res = Find(d1, dArr, sizeArr);         // calls Find<double> by deduction
	res = Find<double>(d1, dArr, sizeArr); // calls Find<double> explicitly
	
	const char* word = "two";
	const char* arr[] = { "one", "two", "three", "four" };
	sizeArr = sizeof(arr) / sizeof(arr[0]);
	res = Find<const char*>(word, arr, sizeArr);  // calls template specialization for const char*s
	res = Find(word, arr, sizeArr);         // calls overloaded Find for const char*s
	
	int *px = &x, *pArr[] = { &x, &x };
	sizeArr = sizeof(pArr) / sizeof(pArr[0]);
	res = Find(px, pArr, sizeArr);    // calls the overloaded Find for pointers
	
	SpreadsheetCell c1(10), c2[] = { SpreadsheetCell(4), SpreadsheetCell(10) };
	sizeArr = sizeof(c2) / sizeof(c2[0]);
	res = Find(c1, c2, sizeArr);                  // calls Find<SpreadsheetCell> by deduction
	res = Find<SpreadsheetCell>(c1, c2, sizeArr); // calls Find<SpreadsheetCell> explicitly
	
	SpreadsheetCell *pc1 = &c1;
	SpreadsheetCell *psa[] = { &c1, &c1 };
	sizeArr = sizeof(psa) / sizeof(psa[0]);
	res = Find(pc1, psa, sizeArr); // Calls the overloaded Find for pointers
}

#include "OneDGrid.h"
void ch_21_4_1(){
	OneDGrid<int> singleDGrid;
	OneDGrid<OneDGrid<int>> twoDGrid;
	OneDGrid<OneDGrid<OneDGrid<int>>> threeDGrid;
	
	singleDGrid[3] = 5;
	twoDGrid[3][3] = 5;
	threeDGrid[3][3][3] = 5;
}

#include "NDGrid.h"
void ch_21_4_2(){
	NDGrid<int, 3> my3DGrid(3);
	my3DGrid[2][1][2] = 5;
	my3DGrid[1][1][1] = 5;
	
	cout << my3DGrid[2][1][2] << endl;
}

#include "TypeInference.hpp"

template<typename T1, typename T2, typename Result>
Result DoAddition(const T1& t1, const T2& t2)
{
	return t1 + t2;
}

template<typename T1, typename T2>
auto DoAddition2(const T1& t1, const T2& t2) -> decltype(t1 + t2)
{
	return t1 + t2;
}

// Using C++14 function return type deduction
template<typename T1, typename T2>
auto DoAddition3(const T1& t1, const T2& t2)
{
	return t1 + t2;
}

void ch_21_5_1(){
	MyInt i(4);
	MyString str("5");
	MyInt a = i + str;		// 9
	MyString b = str + i;	// 54
	
	auto c = DoAddition<MyInt, MyString, MyInt>(i, str);	// 9
//	auto c1 = DoAddition<MyString, MyInt, MyInt>(str, i);	// 9
	
	auto d = DoAddition2(i, str);	// 9
	auto e = DoAddition2(str, i);	// 54
	
	auto f = DoAddition3(i, str);	// 9
	auto g = DoAddition3(str, i);	// 54
	
	a.print();
	b.print();
	c.print();
	d.print();
	e.print();
	f.print();
	g.print();
}

void handleValue(int value){
	cout << "Integer: " << value << endl;
}
void handleValue(double value){
	cout << "Double: " << value << endl;
}
void handleValue(const string& value){
	cout << "String: " << value << endl;
}

// First version using pass-by-value
template<typename T>
void processValues(T arg) {
	handleValue(arg);
}

template<typename T1, typename... Tn>
void processValues(T1 arg1, Tn... args){
	handleValue(arg1);
	processValues(args...);
}

// Second version using pass-by-rvalue-reference
template<typename T>
void processValuesRValueRefs(T&& arg){
	handleValue(std::forward<T>(arg));
}

template<typename T1, typename... Tn>
void processValuesRValueRefs(T1&& arg1, Tn&&... args){
	handleValue(std::forward<T1>(arg1));
	processValuesRValueRefs(std::forward<Tn>(args)...);
}

void ch_21_6(){
	processValues(1, 2, 3.56, "test", 1.1f);
	cout << endl;
	processValuesRValueRefs(1, 2, 3.56, "test", 1.1f);
}

class Mixin1
{
public:
	Mixin1(int i) : mValue(i) {}
	virtual void Mixin1Func() { cout << "Mixin1: " << mValue << endl; }
	
private:
	int mValue;
};

class Mixin2
{
public:
	Mixin2(int i) : mValue(i) {}
	virtual void Mixin2Func() { cout << "Mixin2: " << mValue << endl; }
	
private:
	int mValue;
};

template<typename... Mixins>
class MyClass : public Mixins...
{
public:
	MyClass(const Mixins&... mixins) : Mixins(mixins)... {}
	virtual ~MyClass() {}
};

void ch_21_6_2(){
	MyClass<Mixin1, Mixin2> a(Mixin1(11), Mixin2(22));
	a.Mixin1Func();
	a.Mixin2Func();
	
	MyClass<Mixin1> b(Mixin1(33));
	b.Mixin1Func();
	//b.Mixin2Func();    // Error: does not compile.
}

template<unsigned char f>
class Factorial
{
public:
	static const unsigned long long val = (f * Factorial<f - 1>::val);
};

template<>
class Factorial<0>
{
public:
	static const unsigned long long val = 1;
};

void ch_21_7_1(){
	cout << Factorial<6>::val << endl;
}

template<int i>
class Loop
{
public:
	template <typename FuncType>
	static inline void Do(FuncType func) {
		Loop<i - 1>::Do(func);
		func(i);
	}
};

template<>
class Loop<0>
{
public:
	template <typename FuncType>
	static inline void Do(FuncType /* func */) { }
};

void DoWork(int i)
{
	cout << "DoWork(" << i << ")" << endl;
}

void DoWork2(string str, int i)
{
	cout << "DoWork2(" << str << ", " << i << ")" << endl;
}

void ch_21_7_2(){
	Loop<3>::Do(DoWork);
	cout << endl;
	
	Loop<2>::Do(bind(DoWork2, "TestStr", placeholders::_1));
	cout << endl;
}

template<int n, typename TupleType>
class tuple_print
{
public:
	tuple_print(const TupleType& t) {
		tuple_print<n - 1, TupleType> tp(t);
		cout << get<n - 1>(t) << endl;
	}
};

template<typename TupleType>
class tuple_print<0, TupleType>
{
public:
	tuple_print(const TupleType&) { }
};

template<int n, typename TupleType>
class tuple_print_helper
{
public:
	tuple_print_helper(const TupleType& t) {
		tuple_print_helper<n - 1, TupleType> tp(t);
		cout << get<n - 1>(t) << endl;
	}
};

template<typename TupleType>
class tuple_print_helper<0, TupleType>
{
public:
	tuple_print_helper(const TupleType&) { }
};

template<typename T>
void tuple_print_func(const T& t)
{
	tuple_print_helper<tuple_size<T>::value, T> tph(t);
}


void ch_21_7_3(){
	using MyTuple = tuple<int, string, bool>;
	MyTuple t1(16, "Test", true);
	tuple_print<tuple_size<MyTuple>::value, MyTuple> tp(t1);
	
	auto t2 = make_tuple(167, "Testing", false, 2.3);
	tuple_print_func(t2);
}


template<typename T>
void process_helper(const T& t, true_type)
{
	cout << t << " is an integral type." << endl;
}

template<typename T>
void process_helper(const T& t, false_type)
{
	cout << t << " is a non-integral type." << endl;
}

template<typename T>
void process(const T& t)
{
	process_helper(t, typename is_integral<T>::type());
}

void ch_21_7_4_1(){
	if (is_integral<int>::value) {
		cout << "int is integral" << endl;
	} else {
		cout << "int is not integral" << endl;
	}
	
	if (is_class<string>::value) {
		cout << "string is a class" << endl;
	} else {
		cout << "string is not a class" << endl;
	}
	
	process(123);
	process(2.2);
	process(string("Test"));
}

template<typename T1, typename T2>
void same(const T1& t1, const T2& t2)
{
	bool areTypesTheSame = is_same<T1, T2>::value;
	cout << "'" << t1 << "' and '" << t2 << "' are ";
	cout << (areTypesTheSame ? "the same types." : "different types.") << endl;
}

void ch_21_7_4_2(){
	same(1, 32);
	same(1, 3.01);
	same(3.01, string("Test"));
}

template<typename T1, typename T2>
typename enable_if<is_same<T1, T2>::value, bool>::type
check_type(const T1& t1, const T2& t2)
{
	cout << "'" << t1 << "' and '" << t2 << "' ";
	cout << "are the same types." << endl;
	return true;
}

template<typename T1, typename T2>
typename enable_if<!is_same<T1, T2>::value, bool>::type
check_type(const T1& t1, const T2& t2)
{
	cout << "'" << t1 << "' and '" << t2 << "' ";
	cout << "are different types." << endl;
	return false;
}

void ch_21_7_4_3(){
	check_type(1, 32);
	check_type(1, 3.01);
	check_type(3.01, string("Test"));
}

void ch_21_main(){
//	ch_21_1_1();
//	ch_21_1_1_1();
//	ch_21_1_2();
//	ch_21_1_3();
//	ch_21_1_3_1();
//	ch_21_2();
//	ch_21_2_1();
//	ch_21_3();
//	ch_21_4_1();
//	ch_21_4_2();
//	ch_21_5_1();
//	ch_21_6();
//	ch_21_6_2();
//	ch_21_7_1();
//	ch_21_7_2();
//	ch_21_7_3();
//	ch_21_7_4_1();
//	ch_21_7_4_2();
	ch_21_7_4_3();
	cout << "" << endl;
}
