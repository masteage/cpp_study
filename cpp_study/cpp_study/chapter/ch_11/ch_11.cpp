//
//  ch_11.cpp
//  ch_11
//
//  Created by taeseongsong on 28/10/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "ch_11.hpp"
//#include "Grid.h"
#include "GridString.h"
#include "SpreadsheetCell.h"

using IntGrid = Grid<int>;
typedef Grid<int> IntGrid_02;

void processIntGrid_02(IntGrid& inGrid, IntGrid_02& inGrid_02){
	cout << "processIntGrid_02 called" << endl;
}

void processIntGrid(Grid<int>& inGrid){
	cout << "processIntGrid called" << endl;
}

void ch_11_2_1_3(){
	Grid<int> myIntGrid;
	Grid<double> myDoubleGrid(11, 11);
	myIntGrid.setElementAt(0, 0, 10);
	int x = myIntGrid.getElementAt(0, 0);
	cout << "x : " << x << endl;

	Grid<int> grid2(myIntGrid);
	Grid<int> anotherIntGrid;
	anotherIntGrid = grid2;

	// Use of class template 'Grid' requires template arguments
//	Grid test;
	
	// Too few template arguments for class template 'Grid'
//	Grid<> test; // WILL NOT COMPILE
	

	processIntGrid(myIntGrid);
	processIntGrid_02(myIntGrid,myIntGrid);

	Grid<SpreadsheetCell> mySpreadsheet;
	SpreadsheetCell myCell("Test");
	mySpreadsheet.setElementAt(3, 4, myCell);

	Grid<const char*> myStringGrid;
	myStringGrid.setElementAt(2, 2, "hello");

	Grid<vector<int>> gridOfVectors;
	vector<int> myVector{ 1, 2, 3, 4 };
	gridOfVectors.setElementAt(5, 6, myVector);

	auto myGridp = make_unique<Grid<int>>(2, 2);
	myGridp->setElementAt(0, 0, 10);
	x = myGridp->getElementAt(0, 0);
}


void ch_11_main(){
	ch_11_2_1_3();
	cout << "" << endl;
}
