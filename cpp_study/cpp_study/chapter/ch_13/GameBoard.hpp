//
//  GameBoard.hpp
//  ch_13
//
//  Created by taeseongsong on 25/11/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

class GamePiece {
public:
	const void f() const {};
};

class GameBoard
{
public:
	// general-purpose GameBoard allows user to specify its dimensions
	explicit GameBoard(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	GameBoard(const GameBoard& src); // Copy constructor
	virtual ~GameBoard() noexcept;
	
	GameBoard& operator=(const GameBoard& rhs); // Assignment operator
	
	void setPieceAt(size_t x, size_t y, const GamePiece& inPiece);
	GamePiece& getPieceAt(size_t x, size_t y);
	const GamePiece& getPieceAt(size_t x, size_t y) const;
	
	size_t getHeight() const noexcept{ return mHeight; }
	size_t getWidth() const noexcept{ return mWidth; }
	
	static const size_t kDefaultWidth = 100;
	static const size_t kDefaultHeight = 100;
	
private:
	void copyFrom(const GameBoard& src);
	void freeMemory();
	void allocateMemory();
	
	// Objects dynamically allocate space for the game pieces.
	GamePiece** mCells;
	size_t mWidth, mHeight;
};

#endif /* GameBoard_hpp */
