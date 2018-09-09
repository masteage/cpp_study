//
//  ch_02.cpp
//  cpp_study
//
//  Created by taeseongsong on 2018. 9. 9..
//  Copyright © 2018년 taeseongsong. All rights reserved.
//

#include "ch_02.hpp"

#pragma mark - declare

void c_string_last_char();
char* c_copy_string(const char* str);
void c_copy_string_test(const char* str);
char* c_append_strings(const char* str1, const char* str2, const char* str3);
void c_strlen_sizeof();
void c_string_literal();
void cpp_string();
void cpp_string_literal();
void cpp_raw_string_literal();

#pragma mark - main

void ch_02_main()
{
	c_string_last_char();
	c_strlen_sizeof();
	c_string_literal();
	cpp_string();
	cpp_string_literal();
	cpp_raw_string_literal();
}

#pragma mark - definition
void c_string_last_char()
{
	// copy 01
	const char* str1 = "Hello";
	char* copy = c_copy_string(str1);
	cout << copy << endl;
	delete [] copy;
	copy = nullptr;
	
	// copy 02
	c_copy_string_test(str1);
	
	// append
	const char* str2 = " World";
	const char* str3 = "!";
	char* result = c_append_strings(str1, str2, str3);
	cout << result << endl;
	delete [] result;
	result = nullptr;
}

char* c_copy_string(const char* str)
{
//	int nStringSize = (int)strlen(str);		// last not '\0'
	int nStringSize = (int)strlen(str) + 1;
	char* result = new char[nStringSize];
	strcpy(result, str);
//	result[nStringSize] = 'c';
//	auto s1 = sizeof(result);
	return result;
}

void c_copy_string_test(const char* str)
{
	// test 01
	int nStringSize_01 = (int)strlen(str);		// last not '\0'
	char* result_01 = new char[nStringSize_01];
	strcpy(result_01, str);
	auto size_01 = sizeof(result_01);
	cout << "size_01 : " << size_01 << endl;
	delete [] result_01;
	result_01 = nullptr;
	
	// test 02
	int nStringSize_02 = (int)strlen(str);		// last not '\0'
	char* result_02 = new char[nStringSize_02];
	strcpy(result_02, str);
	result_02[nStringSize_02] = 'c';			// make bug
	auto size_02 = sizeof(result_02);
	cout << "size_02 : " << size_02 << endl;
	delete [] result_02;
	result_02 = nullptr;
	
	// test 03
	int nStringSize_03 = (int)strlen(str) + 1;
	char* result_03 = new char[nStringSize_03];
	strcpy(result_03, str);
	auto size_03 = sizeof(result_03);
	cout << "size_03 : " << size_03 << endl;
	delete [] result_03;
	result_03 = nullptr;
	
	// test 04
	int nStringSize_04 = (int)strlen(str) + 1;
	char* result_04 = new char[nStringSize_04];
	strcpy(result_04, str);
	result_04[nStringSize_04] = 'c';
	auto size_04 = sizeof(result_04);
	cout << "size_04 : " << size_04 << endl;
	delete [] result_04;
	result_04 = nullptr;
}

char* c_append_strings(const char* str1, const char* str2, const char* str3)
{
	char* result = new char[strlen(str1) + strlen(str2) + strlen(str3) + 1];
	strcpy(result, str1);
	strcat(result, str2);
	strcat(result, str3);
	return result;
}

void c_strlen_sizeof()
{
	char text1[] = "abcdefeeeeee";
	size_t s1 = sizeof(text1);	// 7 -> '\0' char include
	size_t s2 = strlen(text1);	// 6
	cout << "char text1[]" << endl << " - sizeof : " << s1 << endl << " - strlen : " << s2 << endl;
	
	const char* text2 = "abcdefdddddss";
	size_t s3 = sizeof(text2);	// is platform-dependent (e.g. 4 bytes for x86, 8 bytes for x64)
	size_t s4 = strlen(text2);	// is 6
	cout << "const char* text2" << endl << " - sizeof : " << s3 << endl << " - strlen : " << s4 << endl;
}

void c_string_literal()
{
//	char* ptr = "hello";	// warning - ISO C++11 does not allow conversion from string literal to 'char *
//	ptr[1] = 'a';			// crash - Thread 1: EXC_BAD_ACCESS (code=2, address=0x100002c48)
//	cout << "sring literal change(pointer) : " << ptr << endl;
	
	const char* ptr_const = "hello";	// const case - not chage
//	ptr_const[1] = 'a';	// Read-only variable is not assignable
	cout << "sring literal (const pointer) : stiring - " << ptr_const << endl;
	
	char arr[] = "hello";
	arr[1] = 'a';
	cout << "sring literal change(array) : string - " << arr << " ,sizeof - " << sizeof(arr) << endl;
}

void cpp_string()
{
	string myString = "hello";
	myString += ", there";
	string myOtherString = myString;
	if (myString == myOtherString) {
		myOtherString[0] = 'H';
	}
	cout << myString << endl;
	cout << myOtherString << endl;
	
	// c_str
	const char* tmp_const_c_str = myString.c_str();
	cout << "before : " << tmp_const_c_str << endl;
	myString = "dddddsjdfjlksjdklf";
	cout << "after : " << tmp_const_c_str << endl;
}

void cpp_string_literal()
{
	auto string_01 = "Hello World";
	auto string_02 = "Hello World"s;
	

//	string_01[0] = 'h';	// Read-only variable is not assignable
	string_02[0] = 'h';
	
	cout << "string01 - " << string_01 << " ,sizeof - " << sizeof(string_01) << " ,strlen - " << strlen(string_01) << endl;
	
//	strlen(string_02);	// No matching function for call to 'strlen'
	cout <<
	"string02 - " << string_02 <<
	" ,sizeof - " << sizeof(string_02) <<
	" ,length() - " << string_02.length() <<
	" ,strlen - " << strlen(string_02.c_str()) <<
	endl;
}

void cpp_raw_string_literal()
{
//	string str1 = "Hello "World"!";		// Expected ';' at end of declaration
	string str2 = "Hello \"World\"!";	// use escape sequence
	string str3 = R"(Hello "World"!)";	// use R"()"

	
	/*
	string str4 = "Line 1
	Line 2 with \t";
*/
	
	string str5 = R"(Line 1
	Line 2 with \t)";
	
//	string str6 = R"(The characters )" are embedded in this string)";		// Expected ';' at end of declaration
	
	// use R"-()-"
	string str7 = R"-(The characters )" are embedded in this string)-";
//	string str8 = R"-(The characters )-" are embedded in this string)-";	// Expected ';' at end of declaration
}






