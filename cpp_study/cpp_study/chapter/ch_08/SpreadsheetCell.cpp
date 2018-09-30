//
//  SpreadsheetCell.cpp
//  cpp_study
//
//  Created by taeseongsong on 30/09/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "SpreadsheetCell.hpp"

#pragma mark - constructor/destructor

SpreadsheetCell::SpreadsheetCell():
mValue(0){
}

SpreadsheetCell::SpreadsheetCell(double initialValue){
	set(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const string& initialValue):
mValue(stringToDouble(initialValue))
,mString(initialValue){
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src){
	mValue = src.mValue;
	mString = src.mString;
}

#pragma mark - operator(unary)
SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs){
	if (this == &rhs) {
		return *this;
	}
	mValue = rhs.mValue;
	mString = rhs.mString;
	return *this;
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& rhs){
	SpreadsheetCell newCell;
	newCell.set(mValue + rhs.mValue);
	return newCell;
}

SpreadsheetCell SpreadsheetCell::operator+(double& rhs){
	return SpreadsheetCell(mValue + rhs);
}

#pragma mark - operator(축약형 산술 연산자)
SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs){
	set(mValue + rhs.mValue);
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs){
	set(mValue - rhs.mValue);
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs){
	set(mValue * rhs.mValue);
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs){
	if (rhs.mValue == 0)
		throw invalid_argument("Divide by zero.");
	set(mValue / rhs.mValue);
	return *this;
}

#pragma mark - operator(binary)
SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue + rhs.mValue);
	return newCell;
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue - rhs.mValue);
	return newCell;
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue * rhs.mValue);
	return newCell;
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	if (rhs.mValue == 0)
		throw invalid_argument("Divide by zero.");
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue / rhs.mValue);
	return newCell;
}


#pragma mark - operator(relational and equality)
bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	return (lhs.mValue == rhs.mValue);
}

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	return (lhs.mValue < rhs.mValue);
}

bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	return (lhs.mValue > rhs.mValue);
}

bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	return (lhs.mValue != rhs.mValue);
}

bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	return (lhs.mValue <= rhs.mValue);
}

bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs){
	return (lhs.mValue >= rhs.mValue);
}

#pragma mark - methods (public)
void SpreadsheetCell::set(double inValue){
	mValue = inValue;
	mString = doubleToString(mValue);
}

void SpreadsheetCell::set(const string& inString){
	mString = inString;
	mValue = stringToDouble(mString);
}

string SpreadsheetCell::doubleToString(double inValue){
	ostringstream ostr;
	ostr << inValue;
	return ostr.str();
}

double SpreadsheetCell::stringToDouble(const string& inString){
	double temp;
	istringstream istr(inString);
	istr >> temp;
	if (istr.fail() || !istr.eof()) {
		return 0;
	}
	return temp;
}

// bad
SpreadsheetCell SpreadsheetCell::add(const SpreadsheetCell& cell) const{
	SpreadsheetCell newCell;
	newCell.set(mValue + cell.mValue);
	return newCell;
}
