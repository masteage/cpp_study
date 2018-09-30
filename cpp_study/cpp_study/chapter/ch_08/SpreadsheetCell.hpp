//
//  SpreadsheetCell.hpp
//  cpp_study
//
//  Created by taeseongsong on 30/09/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
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

public:
	// unary operator
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
//	SpreadsheetCell& operator+(const SpreadsheetCell& rhs);	// bad
	SpreadsheetCell operator+(const SpreadsheetCell& rhs);
	SpreadsheetCell operator+(double& rhs);
	
	// 축약형 산술 연산자
	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	
	// binary operator
	friend SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);

	// relational and equality operator
	friend bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	friend bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
	
public:
	void set(double inValue);
	void set(const std::string& inString);
	double getValue() const;
	const std::string& getString() const;
	
private:
	static std::string doubleToString(double inValue);
	static double stringToDouble(const std::string& inString);

private:
	double mValue;
	std::string mString;
	mutable int mNumAccesses = 0;
	
	// 8.5
public:
	enum class Colors{Red=1, Green, Blue, Yellow};
	void setColor(Colors color){mColor = color;};
private:
	Colors mColor = Colors::Blue;
	
	// 8.7
public:
//	SpreadsheetCell& add(const SpreadsheetCell& cell) const;	// bad
	SpreadsheetCell add(const SpreadsheetCell& cell) const;
};

inline double SpreadsheetCell::getValue() const{
//	mValue++;
	mNumAccesses++;
	return mValue;
}

inline const string& SpreadsheetCell::getString() const{
	mNumAccesses++;
	return mString;
}

#endif /* SpreadsheetCell_hpp */
