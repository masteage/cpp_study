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

void ch_08_8_1_3_01(){
	Spreadsheet s1(4,3);
	printSpreadsheet(s1);
}

void ch_08_8_1_3_02(){
	Spreadsheet s1(2,2), s2(4,3);
	s1 = s2;
}

void ch_08_main(){

	ch_08_8_1_3_01();
//	ch_08_8_1_3_02();
	
	SpreadsheetCell sc1(3);
	Spreadsheet s1(4,3);
	printSpreadsheet(s1);
	
	s1.setCellAt(3, 2, sc1);
//	s1.setCellAt(4, 2, sc1);
	
	
	
	
	cout << "" << endl;
}


