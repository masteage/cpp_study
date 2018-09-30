//
//  ch_08.cpp
//  cpp_study
//
//  Created by taeseongsong on 30/09/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "ch_08.hpp"
#include "Spreadsheet.hpp"
#include "SpreadsheetCell.hpp"

void printSpreadsheet(Spreadsheet s){
	cout<< "" <<endl;
}

void ch_08_8_1_3(){
	SpreadsheetCell sc1(3);
	Spreadsheet s1(4,3);
	printSpreadsheet(s1);
	
	s1.setCellAt(3, 2, sc1);
//	s1.setCellAt(4, 2, sc1);
}
void ch_08_8_1_3_01(){
	Spreadsheet s1(4,3);
	printSpreadsheet(s1);
}

void ch_08_8_1_3_02(){
	Spreadsheet s1(2,2), s2(4,3);
	s1 = s2;
}

void ch_08_8_2_1_1(){
//	int c = Spreadsheet::sCounter;
	cout << "Spreadsheet::getCounter is " << Spreadsheet::getCounter() << endl;
}

void ch_08_8_2_2(){
	cout << "Spreadsheet::kMaxWidth is " << Spreadsheet::kMaxWidth << endl;
	cout << "Spreadsheet::kMaxHeight is " << Spreadsheet::kMaxHeight << endl;
}

void ch_08_8_3_2(){
	SpreadsheetCell myCell(5);
	cout<< myCell.getValue() <<endl;
	myCell.set("6");
	const SpreadsheetCell& anothreCell = myCell;
	cout<< anothreCell.getValue() <<endl;
//	anothreCell.setString("6");
}

void ch_08_8_3_3(){
	class MyClass{
	public:
		void foo(int i){};
//		void foo(double d) = delete;
	};
	
	MyClass c;
	c.foo(123);
	c.foo(1.23);
}

void ch_08_8_3_4(){
	class MyClass{
	public:
//		MyClass(){};
//		MyClass(int i=6, int j=5, int k=10){};
		MyClass(int i, int j=5, int k=10){};
		void foo(int i, int j=5, int k=10){};
	};
	
	MyClass c(4);
	c.foo(123);
	c.foo(123,1);
	c.foo(123,1,3);
	
	MyClass c1(4);
	MyClass c2(4,3);
	MyClass c3(4,3,5);
//	MyClass c4;
	cout<<""<<endl;
	
}

void ch_08_8_4(){
	
}

void ch_08_8_5(){
	SpreadsheetCell myCell(5);
	myCell.setColor(SpreadsheetCell::Colors::Yellow);
}

void ch_08_8_7(){
	SpreadsheetCell myCell(5), anotherCell(7);;
//	SpreadsheetCell aThirdCell = myCell.add(anotherCell);
	SpreadsheetCell aThirdCell = myCell + anotherCell;
	SpreadsheetCell aFourthCell = myCell.operator+(anotherCell);
	
	
	string str = "hello";
//	aThirdCell = myCell + str;
	aThirdCell = myCell + 1;
	aThirdCell = myCell + 2.3;
	aThirdCell = 4 + myCell;
	aThirdCell = 4.5 + myCell;
	aThirdCell = 4.5 + 5.5;
	
	aThirdCell += 10;
	if(aThirdCell >= myCell){
		
	}
	cout << "" << endl;
}

void ch_08_8_7_01(){
}

void ch_08_main(){

	ch_08_8_1_3();
	ch_08_8_1_3_01();
	ch_08_8_1_3_02();
	ch_08_8_2_1_1();
	ch_08_8_2_2();
	ch_08_8_3_2();
	ch_08_8_3_3();
	ch_08_8_3_4();
	ch_08_8_4();
	ch_08_8_5();
	ch_08_8_7();
	
	cout << "" << endl;
}


