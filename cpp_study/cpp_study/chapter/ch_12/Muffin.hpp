//
//  Muffin.hpp
//  ch_12
//
//  Created by taeseongsong on 05/11/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#ifndef Muffin_hpp
#define Muffin_hpp

class Muffin{
public:
	const string& getDescription() const;
	void setDescription(const string& inDesc);
	
	int getSize() const;
	void setSize(int inSize);
	
	bool getHasChocolateChips() const;
	void setHasChocolateChips(bool inChips);
	
	void output();
	
private:
	string mDesc;
	int mSize;
	bool mHasChocolateChips;
};

#endif /* Muffin_hpp */
