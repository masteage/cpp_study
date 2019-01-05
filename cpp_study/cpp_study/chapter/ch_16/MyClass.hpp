//
//  MyClass.hpp
//  ch_16
//
//  Created by taeseongsong on 02/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#ifndef MyClass_hpp
#define MyClass_hpp

class MyClass{
public:
	MyClass(int value){mValue = value;};
	friend bool operator<(const MyClass& lhs, const MyClass& rhs);
	friend bool operator==(const MyClass& lhs, const MyClass& rhs);
private:
	int mValue = 0;
};

#endif /* MyClass_hpp */
