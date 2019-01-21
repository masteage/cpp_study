//
//  TypeInference.hpp
//  ch_21
//
//  Created by taeseongsong on 22/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#ifndef TypeInference_hpp
#define TypeInference_hpp

// Forward class declaration
class MyString;

class MyInt
{
public:
	MyInt(int i) : mValue(i) {}
	MyInt operator+(const MyString& rhs) const;
	int getInt() const { return mValue; }
	void print() const {cout << "mValue : " << mValue << endl;}
private:
	int mValue;
};

class MyString
{
public:
	MyString(const std::string& str) : mString(str) {}
	MyString operator+(const MyInt& rhs) const;
//	friend MyInt operator+(const MyString& lhs, const MyInt& rhs);
//	MyInt operator+(const MyInt& rhs) const;
	const std::string& getString() const { return mString; }
	void print() const {cout << "mString : " << mString << endl;}
private:
	std::string mString;
};


#endif /* TypeInference_hpp */
