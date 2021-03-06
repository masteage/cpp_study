//
//  SpreadsheetCell.hpp
//  ch_21
//
//  Created by taeseongsong on 21/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#ifndef SpreadsheetCell_hpp
#define SpreadsheetCell_hpp

class SpreadsheetCell
{
public:
	SpreadsheetCell();
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(const std::string& initialValue);
	SpreadsheetCell(const SpreadsheetCell& src);
	
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
	
	void set(double inValue);
	void set(const std::string& inString);
	
	double getValue() const { mNumAccesses++; return mValue; }
	const std::string& getString() const { mNumAccesses++; return mString; }
	
	static std::string doubleToString(double inValue);
	static double stringToDouble(const std::string& inString);
	
	friend SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	friend bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	
private:
	double mValue;
	std::string mString;
	
	mutable int mNumAccesses = 0;
};

#endif /* SpreadsheetCell_hpp */
