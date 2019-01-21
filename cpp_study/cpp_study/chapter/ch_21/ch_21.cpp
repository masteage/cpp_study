//
//  ch_21.cpp
//  ch_21
//
//  Created by taeseongsong on 21/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#include "ch_21.hpp"

#include <deque>
#include "Grid.h"
void ch_21_1_1(){
#ifdef	_TEMPLATE_NORMAL_
	Grid<int, vector<int>> myIntVectorGrid;
	Grid<int, deque<int>> myIntDequeGrid;
	
	myIntVectorGrid.setElementAt(3, 4, 5);
	cout << myIntVectorGrid.getElementAt(3, 4) << endl;
	
	myIntDequeGrid.setElementAt(1, 2, 3);
	cout << myIntDequeGrid.getElementAt(1, 2) << endl;
	
	Grid<int, vector<int>> grid2(myIntVectorGrid);
	grid2 = myIntVectorGrid;
	cout << grid2.getElementAt(3, 4) << endl;
	
	// compile error
//	Grid<int, int> test;
#endif	// _TEMPLATE_NORMAL_
}

void ch_21_1_1_1(){
#ifdef _DEFAULT_TEMPLATE_TYPE_
	Grid<int, deque<int>> myDequeGrid;
	Grid<int, vector<int>> myVectorGrid;
	Grid<int> myVectorGrid_01;					// Grid<int, vector<int>>
	Grid<float> myVectorGrid_02;				// Grid<float, vector<float>>
	Grid<int, deque<float>> myDequeGrid_01;		// Grid<int, deque<float>> - logical bug
#endif	// _DEFAULT_TEMPLATE_TYPE_
}

void ch_21_1_2(){
#ifdef _TEMPLATE_TEMPLATE_PARAMETER_
	Grid<int, vector> myGrid;					// Grid<int, vector<int>>
	myGrid.setElementAt(1, 2, 3);
	cout << myGrid.getElementAt(1, 2) << endl;
	Grid<int, vector> myGrid2(myGrid);			// Grid<int, vector<int>>
	Grid<int> myGrid3(myGrid2);					// Grid<int, vector<int>>
	
	// Template argument for template template parameter must be a class template or type alias template
//	Grid<int, vector<int>> myGrid3;
	
	
	// https://en.cppreference.com/w/cpp/memory/allocator
#endif	// _TEMPLATE_TEMPLATE_PARAMETER_
}

#include "SpreadsheetCell.hpp"
void ch_21_1_3(){
#ifdef _NON_TYPE_TEMPLATE_PARAMETER_
	Grid<int> myIntGrid;		// Initial value is 0
	Grid<int, 10> myIntGrid2;	// Initial value is 10
	
	// A non-type template parameter cannot have type 'SpreadsheetCell'
//	SpreadsheetCell defaultCell;
//	Grid<SpreadsheetCell, defaultCell> mySpreadsheet;
	
	// A non-type template parameter cannot have type 'float'
//	Grid<float, 10.0> myFloatGrid;
	
#endif	// _NON_TYPE_TEMPLATE_PARAMETER_
}

namespace {
//	const int defaultInt = 11;
//	const SpreadsheetCell defaultCell(1.2);
	int defaultInt = 11;
	SpreadsheetCell defaultCell(1.2);
}

SpreadsheetCell defaultCellTmp(1.2);
//const SpreadsheetCell defaultCellTmp(1.2);

void ch_21_1_3_1(){
#ifdef _NON_TYPE_TEMPLATE_PARAMETER_REF_
	Grid<int, defaultInt> myIntGrid;
	Grid<SpreadsheetCell, defaultCell> mySpreadsheet;
	Grid<int, defaultInt> myIntGrid2(myIntGrid);
	
	// Non-type template argument does not refer to any declaration
//	Grid<int, 11> myIntGrid3;
	
	// Non-type template argument refers to object 'defaultCell' that does not have linkage
//	SpreadsheetCell defaultCellTmp;
//	Grid<int, defaultCellTmp> mySpreadsheet1;
	
//	static const SpreadsheetCell defaultCellTmp(1.2);
	Grid<SpreadsheetCell, defaultCellTmp> mySpreadsheet2;
#endif	// _NON_TYPE_TEMPLATE_PARAMETER_REF_
}

template <typename T, size_t WIDTH, size_t HEIGHT>
class Grid_Partial{
public:
	Grid_Partial();
private:
	T mCells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
Grid_Partial<T, WIDTH, HEIGHT>::Grid_Partial() : mCells(){}

// partial class specialization
template <size_t WIDTH, size_t HEIGHT>
class Grid_Partial<const char*, WIDTH, HEIGHT>{
public:
	Grid_Partial();
private:
	std::string mCells[WIDTH][HEIGHT];
};

template <size_t WIDTH, size_t HEIGHT>
Grid_Partial<const char*, WIDTH, HEIGHT>::Grid_Partial() : mCells(){}

void ch_21_2(){
	Grid_Partial<int, 10, 10> myGrid;
	Grid_Partial<int, 10, 10> anotherGrid;
	Grid_Partial<int, 2, 2> myIntGrid;				// Uses the original Grid
	Grid_Partial<const char*, 2, 2> myStringGrid;	// Uses the partial specialization
//	Grid_Partial<2, 3> test;
//	myIntGrid = myStringGrid;
}

#include "Grid_Ptr.h"
void ch_21_2_1(){
	Grid_Ptr<int> myIntGrid;     // Uses the non-specialized grid
	Grid_Ptr<int*> psGrid(2, 2); // Uses the partial specialization for pointer types

	psGrid.setElementAt(0, 0, make_unique<int>(1));
	psGrid.setElementAt(0, 1, make_unique<int>(2));
	psGrid.setElementAt(1, 0, make_unique<int>(3));

	Grid_Ptr<int*> psGrid2(psGrid);
	Grid_Ptr<int*> psGrid3;
	psGrid3 = psGrid2;

	auto element = psGrid2.getElementAt(1, 0);
	if (element) {
		cout << *element << endl;
		*element = 6;
	}
	cout << *psGrid.getElementAt(1, 0) << endl;  // psGrid is not modified
	cout << *psGrid2.getElementAt(1, 0) << endl; // psGrid2 is modified
}

void ch_21_main(){
//	ch_21_1_1();
//	ch_21_1_1_1();
//	ch_21_1_2();
//	ch_21_1_3();
//	ch_21_1_3_1();
//	ch_21_2();
	ch_21_2_1();
	cout << "" << endl;
}
