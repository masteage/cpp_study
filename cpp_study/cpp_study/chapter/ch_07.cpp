//
//  ch_07.cpp
//  cpp_study
//
//  Created by taeseongsong on 2018. 9. 16..
//  Copyright © 2018년 taeseongsong. All rights reserved.
//

#include "ch_07.hpp"
#include "SpreadsheetCell.hpp"

void ch_07_3_1_5(){
	
	class SpreadsheetCell_Tmp{
	public:
		SpreadsheetCell_Tmp() : value(0){};
		double value;
	};
	
	class SpreadsheetCell_Tmp_02{
	public:
		SpreadsheetCell_Tmp_02(double d){value = d;};
		double value;
	};
	
	class SomeClass{
	public:
		//		SomeClass(){};	// Constructor for 'SomeClass' must explicitly initialize the member 'mCell' which does not have a default constructor
		SomeClass() : mCell(5.1){};
	private:
		SpreadsheetCell_Tmp_02 mCell;
	};
	
	class SpreadsheetCell_Tmp_03{
	public:
		SpreadsheetCell_Tmp_03(const string& initialValue)
		: mValue(stringToDouble(initialValue)), mString(initialValue){
			//		: mString(initialValue), mValue(stringToDouble(mString)){			// not good
			cout<< "mString : " << mString << " , mValue : " << mValue <<endl;
		}
		double stringToDouble(const std::string& inString) const{
			double dValue = 0;
			istringstream istr(inString);
			istr >> dValue;
			if(istr.fail() || !istr.eof()) {
				return 0;
			}
			return dValue;
		}
	private:
		
		// dtor-intializer order
		double mValue;
		std::string mString;
	};
	
	SpreadsheetCell_Tmp_03 tmp("105.3");
}

void ch_07_3_1_7(){
	class EvenSequence{
	public:
		EvenSequence(initializer_list<double> args){
			if (args.size() % 2 != 0) {
				throw invalid_argument("initializer_list should "
									   "contain even number of elements.");
			}
			mSequence.reserve(args.size());
			//			for (auto value : args) {
			//				mSequence.push_back(value);
			//			}
			mSequence.insert(cend(mSequence),cbegin(args),cend(args));
		}
		
		void dump() const{
			for (auto value : mSequence) {
				cout << value << ", ";
			}
			cout << endl;
		}
	private:
		vector<double> mSequence;
	};
	
	EvenSequence p1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
	//	EvenSequence p1{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
	p1.dump();
	
	try {
		EvenSequence p2 = {1.0, 2.0, 3.0};
	} catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
}

class MyClass_01{
public:
	MyClass_01() : mInt(2),mStr("dd") {};
private:
	int mInt = 1;
	std::string mStr = "test";
private:
	static const int kI1 = 1;
//	static const std::string kStr = "test";	// Static data member of type 'const std::string' (aka 'const basic_string<char, char_traits<char>,
//	static int sI2 = 2;						// Non-const static data member must be initialized out of line
	const int kI3 = 3;
};

class MyClass{
public:
	MyClass(){};
	MyClass(char c) : MyClass(){};
//	MyClass(char c) : MyClass(1.2) {};		// Constructor for 'MyClass' creates a delegation cycle
//	MyClass(double d) : MyClass('m') {};	// Constructor for 'MyClass' creates a delegation cycle
};

void destructor_call_order(){
	cout << "\n\ndestructor_call_order start" << endl;
	SpreadsheetCell myCell(5);
	myCell.mName = "myCell";
	if (myCell.getValue() == 5) {
		SpreadsheetCell anotherCell(6);
		anotherCell.mName = "anotherCell";
	}
	{
		SpreadsheetCell myCell2(4);
		SpreadsheetCell anotherCell2(5);
		myCell2.mName = "myCell2";
		anotherCell2.mName = "anotherCell2";
	}
	cout << "destructor_call_order end\n\n" << endl;
}

void destructor_call_heap()
{
	cout << "\n\ndestructor_call_heap start" << endl;
	SpreadsheetCell* cellPtr1 = new SpreadsheetCell(5);
	cellPtr1->mName = "cellPtr1";
	SpreadsheetCell* cellPtr2 = new SpreadsheetCell(6);	// not destructor call
	cellPtr2->mName = "cellPtr2";
	delete cellPtr1;
	cellPtr1 = nullptr;
	
	cout << "destructor_call_heap end\n\n" << endl;
}

void ch_07_main(){
	SpreadsheetCell tmp_01;
	tmp_01.setValue(10);
	tmp_01.setValue2(20);
	
	SpreadsheetCell tmp_02;
	tmp_02.setValue(20);
	
	// not definition method call error
//	tmp.notDefinitionMethodCall();
	
	// compile error msg
//	Undefined symbols for architecture x86_64:
//		"SpreadsheetCell::notDefinitionMethodCall()", referenced from:
//		ch_07_main() in ch_07.o
//		ld: symbol(s) not found for architecture x86_64
//			clang: error: linker command failed with exit code 1 (use -v to see invocation)
	
	
	// stack object
	SpreadsheetCell myCell, anotherCell;
	myCell.setValue(6);
	anotherCell.setValue(myCell.getValue());
	cout << "myCell : " << myCell.getValue() << endl;
	cout << "anotherCell : " << anotherCell.getValue() << endl;
	
	// heap object
	SpreadsheetCell* myCellp = new SpreadsheetCell();
	myCellp->setValue(3.7);
	cout << "myCellp : " << myCellp->getValue() << " " << myCellp->getString() << endl;
//	(*myCellp).setValue(3.7);
//	cout << "cell 1: " << (*myCellp).getValue() << " " << (*myCellp).getString() << endl;
	delete myCellp;
	myCellp = nullptr;
	
	// heap object - smart pointer
	auto myCellp_smart = make_unique<SpreadsheetCell>();
//	unique_ptr<SpreadsheetCell> myCellp_smart(new SpreadsheetCell());
	myCellp_smart->setValue(3.7);
	cout << "myCellp_smart : " << myCellp_smart->getValue() << " " << myCellp_smart->getString() << endl;
	
	// constructor
	SpreadsheetCell myCell_ctor(5), anotherCell_ctor(4);
	cout << "myCell_ctor : " << myCell_ctor.getValue() << endl;
	cout << "anotherCell_ctor : " << anotherCell_ctor.getValue() << endl;
	
	// not
//	SpreadsheetCell myCell_ctor2.SpreadsheetCell(5);
//	SpreadsheetCell myCell_default_ctor;
//	myCell_default_ctor.SpreadsheetCell(10);
	
	
	// constructor
	// - heap object - smart pointer
	auto myCellp_smart2 = make_unique<SpreadsheetCell>(4);
	// - stack object
	SpreadsheetCell* myCellp2 = new SpreadsheetCell(5);
	SpreadsheetCell* myCellp3 = nullptr;
	myCellp3 = new SpreadsheetCell(10);
	delete myCellp2;myCellp2 = nullptr;
	delete myCellp3;myCellp3 = nullptr;
	
	
	SpreadsheetCell aThirdCell("test");
	SpreadsheetCell aFourthCell(4.4);
	auto aThirdCellp = make_unique<SpreadsheetCell>("5.6");
	cout << "aThirdCell: " << aThirdCell.getValue() << endl;
	cout << "aFourthCell: " << aFourthCell.getValue() << endl;
	cout << "aThirdCellp: " << aThirdCellp->getValue() << endl;
	
	// local temp object
	SpreadsheetCell(10);
	
	// default constructor
	// - error case
	// No matching constructor for initialization of 'SpreadsheetCell_02 [3]'
//	SpreadsheetCell_02 cells[3];
//	SpreadsheetCell_02* myCellp = new SpreadsheetCell_02[10];
//	SpreadsheetCell_02 cells[3] = {SpreadsheetCell_02(0), SpreadsheetCell_02(23), SpreadsheetCell_02(41)};
	
	// - call
	SpreadsheetCell myCell_default_ctor_01;
	auto myCellp_smart3 = make_unique<SpreadsheetCell>();
	
	// - call : bad
	// compile - method declare
	// return : SpreadsheetCell , method name : myCell_default_ctor_02
	// Base of member reference is a function; perhaps you meant to call it with no arguments?
//	SpreadsheetCell myCell_default_ctor_02();
//	myCell_default_ctor_02.setValue(6);
	
	
	
	class MyClass{
	public:
		MyClass() = default;	// explicity defaulted constructor
	};
	class MyClass_02{
	public:
		MyClass_02() = delete;	// explicity deleted constructor
		MyClass_02(int n){};
	};
	
//	MyClass myclass;
//	MyClass_02 myclass_02;	// Call to deleted constructor of 'MyClass_02'
//	MyClass_02 myclass_02(1);
	
	
	ch_07_3_1_5();
	ch_07_3_1_7();
	destructor_call_order();
	destructor_call_heap();
	
	cout << "end" << endl;
}

