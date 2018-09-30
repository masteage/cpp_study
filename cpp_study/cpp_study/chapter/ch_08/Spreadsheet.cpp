//
//  Spreadsheet.cpp
//  cpp_study
//
//  Created by taeseongsong on 30/09/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "Spreadsheet.hpp"

#pragma mark - Spreadsheet

int Spreadsheet::sCounter;		// default 0
//int Spreadsheet::sCounter = 10;

#pragma mark - constructor/destructor
Spreadsheet::Spreadsheet(int inWidth, int inHeight/*, SpreadsheetApplication& theApp*/):
//mWidth(inWidth), mHeight(inHeight)
mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth)
,mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight)
/*,mTheApp(theApp)*/
{
	setID();
	mCells = new SpreadsheetCell*[mWidth];
	for (int i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

Spreadsheet::Spreadsheet(const Spreadsheet &src)/*:mTheApp(src.mTheApp)*/{
	setID();
	copyFrom(src);
}

Spreadsheet::~Spreadsheet(){
	deleteAll();
}

#pragma mark - operator
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs){
	
	// not set ID
//	setID();
	
	// check for self-assignment
	if (this == &rhs) {
		return *this;
	}
	// free the old memory
	deleteAll();

	// copy the new memory
	copyFrom(rhs);

	return *this;
}

#pragma mark - methods (public)

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell){
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}
	mCells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(int x, int y){
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}
	return mCells[x][y];
}

#pragma mark - methods (private)

bool Spreadsheet::inRange(int val, int upper){
	return (val >= 0 && val < upper);
}

void Spreadsheet::copyFrom(const Spreadsheet& src){
	// value set
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	
	// not need (aready null)
//	deleteAll();
	
	// malloc
	mCells = new SpreadsheetCell*[mWidth];
	for (int i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
	
	// deep copy
	for (int i = 0; i < mWidth; i++) {
		for (int j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

void Spreadsheet::deleteAll(){
	for (int i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}
