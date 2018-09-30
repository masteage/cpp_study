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

class Spreadsheet
{
public:
	Spreadsheet(int inWidth, int inHeight);
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
};

#endif /* Spreadsheet_hpp */
