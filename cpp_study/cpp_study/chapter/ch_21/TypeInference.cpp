//
//  TypeInference.cpp
//  ch_21
//
//  Created by taeseongsong on 22/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#include "TypeInference.hpp"

MyInt MyInt::operator+(const MyString& rhs) const
{
	return mValue + stoi(rhs.getString());
}

MyString MyString::operator+(const MyInt& rhs) const
{
	string str = mString;
	str.append(to_string(rhs.getInt()));
	return str;
}

//MyInt operator+(const MyString& lhs, const MyInt& rhs)
//{
//	string str = lhs.mString;
//	str.append(to_string(rhs.getInt()));
//	return stoi(str);
//}
