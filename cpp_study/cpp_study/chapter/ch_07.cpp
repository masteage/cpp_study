//
//  ch_07.cpp
//  cpp_study
//
//  Created by taeseongsong on 2018. 9. 16..
//  Copyright © 2018년 taeseongsong. All rights reserved.
//

#include "ch_07.hpp"
#include "SpreadsheetCell.hpp"

void ch_07_main(){
	SpreadsheetCell tmp_01;
	tmp_01.setValue(10);
	tmp_01.setValue2(20);
	
	SpreadsheetCell tmp_02;
	tmp_02.setValue(20);
	
	// not definition method call error
//	tmp.notDefinitionMethodCall();
	
	// compile error msg
//	Undefined symbols for architecture x86_64:
//		"SpreadsheetCell::notDefinitionMethodCall()", referenced from:
//		ch_07_main() in ch_07.o
//		ld: symbol(s) not found for architecture x86_64
//			clang: error: linker command failed with exit code 1 (use -v to see invocation)
	
	
	// stack object
	SpreadsheetCell myCell, anotherCell;
	myCell.setValue(6);
	anotherCell.setValue(myCell.getValue());
	cout << "myCell : " << myCell.getValue() << endl;
	cout << "anotherCell : " << anotherCell.getValue() << endl;
	
	// heap object
	SpreadsheetCell* myCellp = new SpreadsheetCell();
	myCellp->setValue(3.7);
	cout << "myCellp : " << myCellp->getValue() << " " << myCellp->getString() << endl;
//	(*myCellp).setValue(3.7);
//	cout << "cell 1: " << (*myCellp).getValue() << " " << (*myCellp).getString() << endl;
	delete myCellp;
	myCellp = nullptr;
	
	// heap object - smart pointer
	auto myCellp_smart = make_unique<SpreadsheetCell>();
//	unique_ptr<SpreadsheetCell> myCellp_smart(new SpreadsheetCell());
	myCellp_smart->setValue(3.7);
	cout << "myCellp_smart : " << myCellp_smart->getValue() << " " << myCellp_smart->getString() << endl;
	
	// constructor
	SpreadsheetCell myCell_ctor(5), anotherCell_ctor(4);
	cout << "myCell_ctor : " << myCell_ctor.getValue() << endl;
	cout << "anotherCell_ctor : " << anotherCell_ctor.getValue() << endl;
	
	// not
//	SpreadsheetCell myCell_ctor2.SpreadsheetCell(5);
//	SpreadsheetCell myCell_default_ctor;
//	myCell_default_ctor.SpreadsheetCell(10);
	
	
	// constructor
	// - heap object - smart pointer
	auto myCellp_smart2 = make_unique<SpreadsheetCell>(4);
	// - stack object
	SpreadsheetCell* myCellp2 = new SpreadsheetCell(5);
	SpreadsheetCell* myCellp3 = nullptr;
	myCellp3 = new SpreadsheetCell(10);
	delete myCellp2;myCellp2 = nullptr;
	delete myCellp3;myCellp3 = nullptr;
	
	
	SpreadsheetCell aThirdCell("test");
	SpreadsheetCell aFourthCell(4.4);
	auto aThirdCellp = make_unique<SpreadsheetCell>("5.6");
	cout << "aThirdCell: " << aThirdCell.getValue() << endl;
	cout << "aFourthCell: " << aFourthCell.getValue() << endl;
	cout << "aThirdCellp: " << aThirdCellp->getValue() << endl;
	
	// local temp object
	SpreadsheetCell(10);
	
	// default constructor
	// - error case
	// No matching constructor for initialization of 'SpreadsheetCell_02 [3]'
//	SpreadsheetCell_02 cells[3];
//	SpreadsheetCell_02* myCellp = new SpreadsheetCell_02[10];
//	SpreadsheetCell_02 cells[3] = {SpreadsheetCell_02(0), SpreadsheetCell_02(23), SpreadsheetCell_02(41)};
	
	// - call
	SpreadsheetCell myCell_default_ctor_01;
	myCell_default_ctor_01.setValue(6);
	
	// - call : bad
	// compile - method declare
	// return : SpreadsheetCell , method name : myCell_default_ctor_02
	// Base of member reference is a function; perhaps you meant to call it with no arguments?
//	SpreadsheetCell myCell_default_ctor_02();
//	myCell_default_ctor_02.setValue(6);
	
	
	
	
	
	cout << "end" << endl;
}
