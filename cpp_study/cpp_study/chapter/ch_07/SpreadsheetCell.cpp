//
//  SpreadsheetCell.cpp
//  cpp_study
//
//  Created by taeseongsong on 2018. 9. 16..
//  Copyright © 2018년 taeseongsong. All rights reserved.
//

#include "SpreadsheetCell.hpp"

#pragma mark - other
void printCell(const SpreadsheetCell& inCell){
	cout << inCell.getString() << endl;
}

// class definition
#pragma mark - SpreadsheetCell

//public:
#pragma mark - constructor
SpreadsheetCell::SpreadsheetCell(){
//	setValue(0);
	mValue = 0;
}

SpreadsheetCell::SpreadsheetCell(double initialValue){
	setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const std::string& initialValue){
	setString(initialValue);
//	SpreadsheetCell(stringToDouble(initialValue));	// bug
}

#pragma mark - method
void SpreadsheetCell::setValue(double inValue){
	mValue = inValue;
	mString = doubleToString(mValue);
	std::cout << "SpreadsheetCell::" << __FUNCTION__ << " called" << endl;
	cout << "value : ";
	printCell(*this);
}

double SpreadsheetCell::getValue() const{
//	mValue = 10;	// ERROR : Cannot assign to non-static data member within const member function 'getValue'
	return mValue;
}

void SpreadsheetCell::setString(const string& inString){
	mString = inString;
	mValue = stringToDouble(mString);
}

const string& SpreadsheetCell::getString() const{
	return mString;
}

//private:
std::string SpreadsheetCell::doubleToString(double inValue) const{
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadsheetCell::stringToDouble(const std::string& inString) const{
	double dValue = 0;
	istringstream istr(inString);
	istr >> dValue;
	if(istr.fail() || !istr.eof()) {
		return 0;
	}
	return dValue;
}

void SpreadsheetCell::setValue2(double value2){
	value2 = value2;
	mString = doubleToString(value2);
	
//	this->value2 = value2;
//	mString = doubleToString(this->value2);
}










