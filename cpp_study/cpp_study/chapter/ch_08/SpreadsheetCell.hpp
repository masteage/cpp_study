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
	SpreadsheetCell(const std::string& initialValue);
	SpreadsheetCell(const SpreadsheetCell& src);

public:
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
	
public:
	void setValue(double inValue);
	double getValue() const;
	void setString(const std::string& inString);
	const std::string& getString() const;
	
private:
	std::string doubleToString(double inValue) const;
	double stringToDouble(const std::string& inString) const;

private:
	double mValue;
	std::string mString;
};

#endif /* SpreadsheetCell_hpp */
