//
//  Grid_Ptr.h
//  ch_21
//
//  Created by taeseongsong on 22/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#ifndef Grid_Ptr_h
#define Grid_Ptr_h

template <typename T>
class Grid_Ptr
{
public:
	explicit Grid_Ptr(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	virtual ~Grid_Ptr();
	
	// Sets an element at a given location. The element is copied.
	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;
	
	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;
	
private:
	void initializeCellsContainer();
	std::vector<std::vector<T>> mCells;
	size_t mWidth, mHeight;
};

template <typename T>
Grid_Ptr<T>::Grid_Ptr(size_t inWidth, size_t inHeight)
: mWidth(inWidth)
, mHeight(inHeight)
{
	initializeCellsContainer();
}

template <typename T>
Grid_Ptr<T>::~Grid_Ptr()
{
	// Nothing to do, the vector will clean up itself.
}

template <typename T>
void Grid_Ptr<T>::initializeCellsContainer()
{
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
	}
}

template <typename T>
void Grid_Ptr<T>::setElementAt(size_t x, size_t y, const T& inElem)
{
	mCells[x][y] = inElem;
}

template <typename T>
T& Grid_Ptr<T>::getElementAt(size_t x, size_t y)
{
	return mCells[x][y];
}

template <typename T>
const T& Grid_Ptr<T>::getElementAt(size_t x, size_t y) const
{
	return mCells[x][y];
}








template <typename T>
class Grid_Ptr<T*>
{
public:
	explicit Grid_Ptr(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	Grid_Ptr(const Grid_Ptr<T*>& src);
	virtual ~Grid_Ptr();
	Grid_Ptr<T*>& operator=(const Grid_Ptr<T*>& rhs);
	
	// The Grid_Ptr becomes the owner of the element!
	void setElementAt(size_t x, size_t y, std::unique_ptr<T> inElem);
	T* getElementAt(size_t x, size_t y);
	const T* getElementAt(size_t x, size_t y) const;
	
	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;
	
private:
	void initializeCellsContainer();
	void copyFrom(const Grid_Ptr<T*>& src);
	std::vector<std::vector<std::unique_ptr<T>>> mCells;
	size_t mWidth, mHeight;
};

template <typename T>
Grid_Ptr<T*>::Grid_Ptr(size_t inWidth, size_t inHeight)
: mWidth(inWidth)
, mHeight(inHeight)
{
	initializeCellsContainer();
}

template <typename T>
Grid_Ptr<T*>::Grid_Ptr(const Grid_Ptr<T*>& src)
{
	copyFrom(src);
}

template <typename T>
Grid_Ptr<T*>::~Grid_Ptr()
{
	// Nothing to do, the vector and the smart pointers will clean up themselves.
}

template <typename T>
void Grid_Ptr<T*>::initializeCellsContainer()
{
	// clear() will clean up all vectors and smart pointers.
	mCells.clear();
	
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
	}
}

template <typename T>
void Grid_Ptr<T*>::copyFrom(const Grid_Ptr<T*>& src)
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	
	initializeCellsContainer();
	
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			// Make a deep copy of the element by using its copy constructor.
			if (src.mCells[i][j]) {
				mCells[i][j].reset(new T(*(src.mCells[i][j])));
			}
		}
	}
}

template <typename T>
Grid_Ptr<T*>& Grid_Ptr<T*>::operator=(const Grid_Ptr<T*>& rhs)
{
	// Check for self-assignment.
	if (this == &rhs) {
		return *this;
	}
	
	// Perform the copy.
	copyFrom(rhs);
	
	return *this;
}

template <typename T>
void Grid_Ptr<T*>::setElementAt(size_t x, size_t y, std::unique_ptr<T> inElem)
{
	mCells[x][y] = std::move(inElem);
}

template <typename T>
T* Grid_Ptr<T*>::getElementAt(size_t x, size_t y)
{
	return mCells[x][y].get();
}

template <typename T>
const T* Grid_Ptr<T*>::getElementAt(size_t x, size_t y) const
{
	return mCells[x][y].get();
}


#endif /* Grid_Ptr_h */
