//
//  myClass.h
//  ch_13
//
//  Created by taeseongsong on 25/11/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#ifndef myClass_h
#define myClass_h

class SubObject
{
public:
	SubObject(int i);
};

SubObject::SubObject(int /*i*/)
{
	throw runtime_error("Exception by SubObject ctor");
}

class MyClass
{
public:
	MyClass();
private:
	SubObject mSubObject;
};


MyClass::MyClass()
try
	: mSubObject(42)
{
}
catch (const exception& e)
{
	cout << "function-try-block caught: '" << e.what() << "'" << endl;
	
	}
#endif /* myClass_h */
