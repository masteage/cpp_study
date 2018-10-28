//
//  GridDefinitions.h
//  ch_11
//
//  Created by taeseongsong on 28/10/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#ifndef GridDefinitions_h
#define GridDefinitions_h

#include "Grid.h"

template <typename T>
Grid<T>::Grid(size_t inWidth, size_t inHeight)
: mWidth(inWidth)
, mHeight(inHeight)
{
	initializeCellsContainer();
}

template <typename T>
Grid<T>::~Grid()
{
	// Nothing to do, the vector will clean up itself.
}

template <typename T>
void Grid<T>::initializeCellsContainer()
{
	mCells.resize(mWidth);
	// for (auto& column : mCells) {
	for (std::vector<T>& column : mCells) {
		column.resize(mHeight);
	}
}

template <typename T>
void Grid<T>::setElementAt(size_t x, size_t y, const T& inElem)
{
	mCells[x][y] = inElem;
}

template <typename T>
T& Grid<T>::getElementAt(size_t x, size_t y)
{
	return mCells[x][y];
}

template <typename T>
const T& Grid<T>::getElementAt(size_t x, size_t y) const
{
	return mCells[x][y];
}

template class Grid<int>;
template class Grid<double>;
template class Grid<std::vector<int>>;

#endif /* GridDefinitions_h */
