//
//  ch_13.cpp
//  ch_13
//
//  Created by taeseongsong on 25/11/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "ch_13.hpp"

int SafeDivide(int num, int den){
	if (den == 0)
//		throw logic_error("Divide by zero");
		throw invalid_argument("Divide by zero");
	return num / den;
}

void ch_13_2_1_SafeDivide(){
	try {
		cout << SafeDivide(5, 2) << endl;	// 2
		cout << SafeDivide(10, 0) << endl;	// exception
		cout << SafeDivide(3, 3) << endl;	// 1
	} catch (const invalid_argument& e) {
		cerr << typeid(e).name() << " - Caught exception : " << e.what() << endl;
	} catch (const logic_error& e) {
		cerr << typeid(e).name() << "invalid_argument - Caught exception : " << e.what() << endl;
	}
	cout << "try catch after" << endl;
}

void g(){
	throw invalid_argument("Some exception");
}

void f(){
	try {
		g();
	} catch (const invalid_argument& e) {
		cerr << "caught in f: " << e.what() << endl;
		throw;  // rethrow - 여기서 throw 하지 않으면 이후 구문은 처리가 진행됨 (catch 처리가 되었기 떄문)
	}
	cout << "f() catch after" << endl;
}
void ch_13_2_1_Rethrow(){
	try {
		f();
		cout << "f() call after" << endl;
	} catch (const invalid_argument& e) {
		cerr << "caught in main: " << e.what() << endl;
	}
	cout << "f() call, catch after" << endl;
}

#include <fstream>
#include <iostream>
//#include <exception>
void myTerminate(){
	cout << "Uncaught exception!" << endl;
	exit(1);
}
void readIntegerFile_exception(const string& fileName, vector<int>& dest){
	ifstream istr;
	int temp;
	
	// file open
	istr.open(fileName.c_str());
	if (istr.fail()) {
//		throw exception();				// exception
//		throw 5;						// int
//		throw "Unable to open file : fileName";	// char*
//		throw runtime_error("Unable to open the file. : " + fileName);
//		throw invalid_argument("Unable to open the file. : " + fileName);
//		throw length_error("my length error" + fileName);
		throw 5.4f;
	}
	
	// file read
	while (istr >> temp) {
		dest.push_back(temp);
	}
	
	// file read(eof) fail
	if (!istr.eof()) {
		throw runtime_error("Error reading the file.");
	}
}

void ch_13_2_1_readIntegerFile(){
	vector<int> myInts;
	const string fileName = "IntegerFile.txt";
//	terminate_handler old_terminate_handler = set_terminate(myTerminate);
	try {
		readIntegerFile_exception(fileName, myInts);
	} catch (int e) {
		cerr << "Unable to open file " << fileName << " (" << e << ")" << endl;
		return;
	} catch (const char* e) {
		cerr << e << endl;
		return;
	} catch (const invalid_argument& e) {
		cerr << "exception class - " << typeid(e).name() << endl;
		cerr << "e.what() - " << e.what() << endl;
		return;
	} catch (const runtime_error& e) {
		cerr << "exception class - " << typeid(e).name() << endl;
		cerr << "e.what() - " << e.what() << endl;
		return;
	} catch (const logic_error& e) {
		cerr << "exception class - " << typeid(e).name() << endl;
		cerr << "e.what() - " << e.what() << endl;
		return;
	} catch (const exception& e) {
		cerr << "exception class - " << typeid(e).name() << endl;
		cerr << "e.what() - " << e.what() << endl;
		return;	// out function
		

		// invalid_argument -> logic_error -> exception
		// Exception of type 'const std::invalid_argument &' will be caught by earlier handler
//	} catch (const invalid_argument& e) {
//		cerr << "exception class - " << typeid(e).name() << endl;
//		cerr << "e.what() - " << e.what() << endl;
//		return;
	} catch (...) {
		cerr << "Exception !!" << endl;
		return;
	}
//	set_terminate(old_terminate_handler);
	
	for (const auto element : myInts) {
		cout << element << " ";
	}
	cout << endl;
}

void readIntegerFile_AnyThrow(const string& fileName, vector<int>& dest){
	throw invalid_argument("test");
}
void readIntegerFile_ThrowList(const string& fileName, vector<int>& dest) throw (invalid_argument, runtime_error){
	throw invalid_argument("test");
//	throw length_error("my length error");	// crash
//	throw 5;								// crash
}
void readIntegerFile_NoExcept(const string& fileName, vector<int>& dest) noexcept{
//	'readIntegerFile_NoExcept' has a non-throwing exception specification but can still throw
//	throw invalid_argument("test");	// crash
}
void readIntegerFile_NoThrow(const string& fileName, vector<int>& dest) throw(){
//	'readIntegerFile_NoThrow' has a non-throwing exception specification but can still throw
//	throw invalid_argument("test");	// crash
}

void myUnexpected(){
	cerr << "Unexpected exception!" << endl;
	throw runtime_error("");
}
void ch_13_2_4(){
	string fileName = "filename";
	vector<int> v;
	
//	unexpected_handler old_unexpected_handler = set_unexpected(myUnexpected);
	try{
		readIntegerFile_AnyThrow(fileName, v);
//		readIntegerFile_ThrowList(fileName, v);
//		readIntegerFile_NoExcept(fileName, v);	// crash
//		readIntegerFile_NoThrow(fileName, v);	// crash
	} catch (...) {
		cerr << "Exception !!" << endl;
		return;
	}
//	set_unexpected(old_unexpected_handler);
}

void ch_13_2_5_2(){
	class Base
	{
	public:
		virtual ~Base() {}
		virtual void func() throw(exception) { cout << "Base!\n"; }
	};
	
	class Derived : public Base
	{
	public:
		virtual void func() noexcept { cout << "Derived!\n"; }
//		virtual void func() throw(exception, runtime_error) { cout << "Derived!\n"; }
//		virtual void func() throw(runtime_error) { cout << "Derived!\n"; }
//		virtual void func() throw() { cout << "Derived!\n"; }
	};
	
	
	class Base_02
	{
	public:
		virtual ~Base_02() {}
		virtual void func() throw(runtime_error) { cout << "Base!\n"; }
//		virtual void func() throw(runtime_error, invalid_argument) { cout << "Base!\n"; }
	};
	
	class Derived_02 : public Base_02
	{
	public:
//		virtual void func() noexcept { cout << "Derived!\n"; }
//		virtual void func() throw(exception, runtime_error) { cout << "Derived!\n"; }	// error
//		virtual void func() throw(exception) { cout << "Derived!\n"; }					// error
	};
	
	Derived d;
	Derived_02 d_02;
}

#include "FileError.hpp"
void readIntegerFile_FileError(const string& fileName, vector<int>& dest)
{
	ifstream istr;
	int temp;
	string line;
	int lineNumber = 0;
	
	// file open
	istr.open(fileName.c_str());
	if (istr.fail()) {
		throw FileOpenError(fileName);
	}
	
	// file read
	while (!istr.eof()) {
		getline(istr, line);
		lineNumber++;
		
		istringstream lineStream(line);
		while (lineStream >> temp) {
			dest.push_back(temp);
		}
		
		if (!lineStream.eof()) {
			throw FileReadError(fileName, lineNumber);
		}
	}
}

void ch_13_3_3(){
	vector<int> myInts;
	const string fileName = "IntegerFile.txt";
	
	try {
		readIntegerFile_FileError(fileName, myInts);
	} catch (const FileError& e) {
		cerr << e.what() << endl;
		return;
	}
	
	for (const auto element : myInts) {
		cout << element << " ";
	}
	cout << endl;
}

class MyException : public std::exception
{
public:
	MyException(const char* msg) : mMsg(msg) {}
	virtual ~MyException() noexcept {}
	virtual const char* what() const noexcept override { return mMsg.c_str(); }
private:
	std::string mMsg;
};

void doSomething(){
	try {
		throw std::runtime_error("Throwing a runtime_error exception");
	} catch (const std::runtime_error& e) {
		std::cout << __func__ << " caught a runtime_error" << std::endl;
		std::cout << __func__ << " throwing MyException" << std::endl;
		
		// normal
//		throw MyException("MyException with nested runtime_error");
		
		// with nested
		std::throw_with_nested(MyException("MyException with nested runtime_error"));
	}
}

void ch_13_3_4(){
	try {
		doSomething();
	} catch (const MyException& e) {
		std::cout << __func__ << " caught MyException: " << e.what() << std::endl;
		
		// 01
//		const std::nested_exception* pNested = dynamic_cast<const std::nested_exception*>(&e);
//		if (pNested) {
//			try {
//				pNested->rethrow_nested();
//			} catch (const std::runtime_error& e) {
//				std::cout << "  Nested exception: " << e.what() << std::endl;
//			}
//		}
		
		// 02
		try {
			rethrow_if_nested(e);
//		} catch (const exception& e) {
		} catch (const runtime_error& e) {
			cout << "  Nested exception: " << e.what() << endl;
		}
	}
}

void funcTwo(){
	ifstream istr;
	istr.open("filename");
	throw exception();
	
	// Code will never be executed
	// istr 소멸자(+close) 는 local 변수 이기 때문에 호출되지만, 그렇지 않은경우 위험
	istr.close();
}

void funcOne(){
	string str1;
	string* str2 = new string();
	funcTwo();
	
	// funcTwo 에서 throw 일경우 해당 code 호출 되지 않음.
	delete str2;
}

void funcOne_SmartPtr()
{
	string str1;
	auto str2 = make_unique<string>("hello");
	funcTwo();
}

void funcOne_catchRethrow(){
	string str1;
	string* str2 = new string();
	try {
		funcTwo();
	} catch (...) {
		delete str2;
		throw;
	}
	delete str2;
}

void ch_13_4(){
	try {
		funcOne();
//		funcOne_SmartPtr();
//		funcOne_catchRethrow();
	} catch (const exception& /* e */) {
		cerr << "Exception caught!" << endl;
		return;
	}
}

void ch_13_5_1(){
	int* ptr;
	size_t numInts = numeric_limits<int>::max();
	
	try {
		ptr = new int[numInts];
//		throw bad_alloc();
		// make malloc_error_break
		for(size_t i = 0 ; i < numInts ; i++){
			int* tmp = new int[numInts];
		}
	} catch (const bad_alloc& e) {
		cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory: " << e.what() << endl;
		return;
	}
}

void ch_13_5_1_1(){
	int* ptr;
	size_t numInts = numeric_limits<int>::max();
	ptr = new(nothrow) int[numInts];
	if (ptr == nullptr) {
		cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory!" << endl;
		return;
	}
	
	// make malloc_error_break
	for(size_t i = 0 ; i < numInts ; i++){
		int* tmp = new(nothrow) int[numInts];
		if (tmp == nullptr) {
			cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory!" << endl;
			return;
		}
	}
}

class PleaseTerminateMe : public bad_alloc { };
void myNewHandler(){
	cerr << "Unable to allocate memory." << endl;
	throw PleaseTerminateMe();
}

void ch_13_5_1_2(){
	try {
		new_handler oldHandler = set_new_handler(myNewHandler);
		size_t numInts = numeric_limits<int>::max();
		int* ptr = new int[numInts];
		
		// make malloc_error_break
		for(size_t i = 0 ; i < numInts ; i++){
			int* tmp = new int[numInts];
		}
		
		set_new_handler(oldHandler);
	} catch (const PleaseTerminateMe&) {
		cerr << __FILE__ << "(" << __LINE__
		<< "): Terminating program." << endl;
		return;
	}
}


class Element
{
private:
	int mValue;
};

class Matrix
{
public:
	Matrix(size_t width, size_t height);
	virtual ~Matrix();
	
private:
	size_t mWidth;
	size_t mHeight;
	Element** mMatrix;
};

Matrix::Matrix(size_t width, size_t height)
: mWidth(width)
, mHeight(height)
, mMatrix(nullptr)
{
	mMatrix = new Element*[width];
	
	// make malloc_error_break
//	size_t numInts = numeric_limits<int>::max();
//	for(size_t i = 0 ; i < numInts ; i++){
//		int* tmp = new int[numInts];
//	}

	size_t i = 0;
	try {
		for (i = 0; i < width; ++i)
			mMatrix[i] = new Element[height];
		
		// make malloc_error_break
//		size_t numInts = numeric_limits<int>::max();
//		for(size_t i = 0 ; i < numInts ; i++){
//			int* tmp = new int[numInts];
//		}
	} catch (...) {
		cout << "Exception caught in constructor, cleaning up..." << endl;
		for (size_t j = 0; j < i; j++) {
			delete[] mMatrix[j];
		}
		delete[] mMatrix;
		mMatrix = nullptr;
		throw bad_alloc();
	}
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < mWidth; ++i)
		delete[] mMatrix[i];
	delete[] mMatrix;
	mMatrix = nullptr;
}

void ch_13_5_2(){
	try {
		Matrix m(5,5);
	} catch (const bad_alloc& e) {
		cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory: " << e.what() << endl;
		return;
	}
}


#include "myClass.h"
void ch_13_5_3(){
	try {
		MyClass m;
	} catch (const exception& e) {
		cout << "main() caught: '" << e.what() << "'" << endl;
	}
}

#include "GameBoard.hpp"
void processGameBoard(const GameBoard& board){
	const GamePiece& piece = board.getPieceAt(0, 0);
	
	// Doesn't compile
//	board.setPieceAt(1, 2, piece);
}

void ch_13_6(){
	GameBoard board(10, 10);
	GamePiece piece;
	
	board.setPieceAt(0, 0, piece);
	board.setPieceAt(0, 1, board.getPieceAt(0, 0));
	
	GameBoard board2;
	board2 = board;
	
	processGameBoard(board2);
}

void ch_13_main(){
//	ch_13_2_1_SafeDivide();
//	ch_13_2_1_Rethrow();
//	ch_13_2_1_readIntegerFile();
//	ch_13_2_4();
//	ch_13_2_5_2();
//	ch_13_3_3();
//	ch_13_3_4();
//	ch_13_4();
//	ch_13_5_1();
//	ch_13_5_1_1();
//	ch_13_5_1_2();
//	ch_13_5_2();
//	ch_13_5_3();
	ch_13_6();
	cout << "" << endl;
}
