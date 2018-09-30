//
//  Spreadsheet.hpp
//  cpp_study
//
//  Created by taeseongsong on 30/09/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#ifndef Spreadsheet_hpp
#define Spreadsheet_hpp

#include "SpreadsheetCell.hpp"

//class SpreadsheetApplication;
class Spreadsheet
{
public:
	Spreadsheet(int inWidth, int inHeight/*, SpreadsheetApplication& theApp*/);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();

public:
	Spreadsheet& operator=(const Spreadsheet& rhs);
	
public:
	void setCellAt(int x, int y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(int x, int y);
	
private:
	bool inRange(int val, int upper);
	void copyFrom(const Spreadsheet& src);
	void deleteAll();

private:
	int mWidth, mHeight;
	SpreadsheetCell** mCells;
//	SpreadsheetApplication& mTheApp;
	
	
	// 8.2.1
public:
	static int getCounter() {return sCounter;};
	int getID() const{return mId;};
	
private:
	static int sCounter;
	int mId;
	void setID(){mId = Spreadsheet::sCounter++;}
	
	// 8.2.2
public:
	static const int kMaxHeight = 100;
	static const int kMaxWidth = 100;
};

#endif /* Spreadsheet_hpp */
