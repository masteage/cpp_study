//
//  Muffin.cpp
//  ch_12
//
//  Created by taeseongsong on 05/11/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "Muffin.hpp"

const string& Muffin::getDescription() const { return mDesc; }
void Muffin::setDescription(const string& inDesc) { mDesc = inDesc; }
int Muffin::getSize() const { return mSize; }
void Muffin::setSize(int inSize) { mSize = inSize; }
bool Muffin::getHasChocolateChips() const { return mHasChocolateChips; }
void Muffin::setHasChocolateChips(bool inChips) { mHasChocolateChips = inChips; }
void Muffin::output()
{
	printf("%s, Size is %d, %s\n", getDescription().c_str(), getSize(), (getHasChocolateChips() ? "has chips" : "no chips"));
}
