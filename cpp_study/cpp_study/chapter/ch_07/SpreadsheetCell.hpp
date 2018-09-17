//
//  SpreadsheetCell.hpp
//  cpp_study
//
//  Created by taeseongsong on 2018. 9. 16..
//  Copyright © 2018년 taeseongsong. All rights reserved.
//

#ifndef SpreadsheetCell_hpp
#define SpreadsheetCell_hpp

class SpreadsheetCell;


void printCell(const SpreadsheetCell& inCell);

// class declare
class SpreadsheetCell{
	
	// - default access modifier (private)
	int nDefaultAccessModifierVariable;
	void DefaultAccessModifierMethod(){return;};
	
public:
	SpreadsheetCell();
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(const std::string& initialValue);
	
	std::string mName = "";
	~SpreadsheetCell(){cout<< mName << "'s ~SpreadsheetCell() called" <<endl;};
	
	
	// - member method
	void setValue(double inValue);
	double getValue() const;		// const member method (not change variable)
//	double getValue() const;		// ERROR: Class member cannot be redeclared
	void setString(const std::string& inString);
	const std::string& getString() const;
	
protected:
	
private:
	std::string doubleToString(double inValue) const;
//	const std::string& doubleToString(double inValue) const;
	double stringToDouble(const std::string& inString) const;
	
	// - member variable
	double mValue;
//	double mValue;	// ERROR: Duplicate member 'mValue'
	std::string mString;
	
	
	
	// - access modifier
public:			// r/w - any
protected:		// r/w - same class, derived class
private:		// r/w - only class
	
	
public:
	void notDefinitionMethodCall();
	
	
public:
	void setValue2(double value2);
	double value2;
};	// ERROR: Expected ';' after class


struct STRUCT_SpreadsheetCell{
	// - default access modifier (public)
	void setValue(double inValue);
	double getValue() const;
protected:
	double mValue;
};

class SpreadsheetCell_02{
public:
	SpreadsheetCell_02(double initialValue){setValue(initialValue);};
	void setValue(double inValue){value = inValue;};
	double getValue() const{return value;};
private:
	double value;
};

#endif /* SpreadsheetCell_hpp */
