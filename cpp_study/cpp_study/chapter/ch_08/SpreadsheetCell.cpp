//
//  SpreadsheetCell.cpp
//  cpp_study
//
//  Created by taeseongsong on 30/09/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "SpreadsheetCell.hpp"

SpreadsheetCell::SpreadsheetCell()
: mValue(0)
{
}

SpreadsheetCell::SpreadsheetCell(double initialValue)
{
	setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const string& initialValue)
: mValue(stringToDouble(initialValue))
, mString(initialValue)
{
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
{
	mValue = src.mValue;
	mString = src.mString;
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	mValue = rhs.mValue;
	mString = rhs.mString;
	return *this;
}

void SpreadsheetCell::setValue(double inValue)
{
	mValue = inValue;
	mString = doubleToString(mValue);
}

double SpreadsheetCell::getValue() const
{
	return mValue;
}

void SpreadsheetCell::setString(const string& inString)
{
	mString = inString;
	mValue = stringToDouble(mString);
}

const string& SpreadsheetCell::getString() const
{
	return mString;
}

string SpreadsheetCell::doubleToString(double inValue) const
{
	ostringstream ostr;
	
	ostr << inValue;
	return ostr.str();
}

double SpreadsheetCell::stringToDouble(const string& inString) const
{
	double temp;
	
	istringstream istr(inString);
	
	istr >> temp;
	if (istr.fail() || !istr.eof()) {
		return 0;
	}
	return temp;
}

