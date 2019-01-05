//
//  MyClass.cpp
//  ch_16
//
//  Created by taeseongsong on 02/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#include "MyClass.hpp"

bool operator<(const MyClass& lhs, const MyClass& rhs){
	return lhs.mValue < rhs.mValue;
}

bool operator==(const MyClass& lhs, const MyClass& rhs){
	return lhs.mValue == rhs.mValue;
}
