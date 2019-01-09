//
//  ch_17.cpp
//  ch_17
//
//  Created by taeseongsong on 07/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#include "ch_17.hpp"


#include <algorithm>
#include <vector>
#include <iostream>

void ch_17_1_1_find(){
	vector<int> myVector;
	myVector.push_back(3);
	myVector.push_back(8);
	myVector.push_back(5);
	myVector.push_back(100);
	myVector.push_back(9);
	
//	int num = 3;
	int num = 7;
	auto endIt = cend(myVector);
	auto it = find(cbegin(myVector), endIt, num);
	if (it == endIt) {
		cout << "Could not find " << num << endl;
	} else {
		cout << "Found " << *it << endl;
	}
}

bool perfectScore(int num){
	return (num >= 100);
}

void ch_17_1_1_find_if(){
	vector<int> myVector;
	myVector.push_back(30);
	myVector.push_back(90);
//	myVector.push_back(100);
	myVector.push_back(20);
	
	auto endIt = cend(myVector);
	
	// find if
//	auto it = find_if(cbegin(myVector), endIt, perfectScore);
	
	// lamda
	auto it = find_if(cbegin(myVector), endIt, [](int num){return num >= 100;});
	if (it == endIt) {
		cout << "No perfect scores" << endl;
	} else {
		cout << "Found a \"perfect\" score of " << *it << endl;
	}
}

#include <numeric>
double arithmeticMean(const vector<int>& nums){
//	https://en.cppreference.com/w/cpp/algorithm/accumulate
	double sum = accumulate(cbegin(nums), cend(nums), 0/*15*/);
	return sum / nums.size();
}

int product(int num1, int num2){
	return num1 * num2;
}

#include <cmath>
double geometricMean(const vector<int>& nums){
	double mult = accumulate(cbegin(nums), cend(nums), 1/*100*/, product);
	return pow(mult, 1.0 / nums.size());
}

double geometricMeanLambda(const vector<int>& nums){
	double mult = accumulate(
							 cbegin(nums),
							 cend(nums),
							 1,
							 [](int num1, int num2){
								 return num1 * num2;
							 }
							 );
	return pow(mult, 1.0 / nums.size());
}

void ch_17_1_2(){
	vector<int> myVector;
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(10);
	
	cout << "The arithmetic mean is " << arithmeticMean(myVector) << endl;
	cout << "The geometric mean is " << geometricMean(myVector) << endl;
	cout << "The geometric mean (Lambda version) is " << geometricMeanLambda(myVector) << endl;
	
	cout << "" << endl;
}

void ch_17_2_1(){
	// Basic lambda
	auto basicLambda = []{ cout << "Hello from Lambda" << endl; };
	basicLambda();
	
	// Lambda with parameters
	auto parametersLambda = [](int value){ cout << "The value is " << value << endl; };
	parametersLambda(42);
	
	// Lambda returning a value
	auto returningLambda = [](int a, int b) -> int { return a + b; };
	int sum = returningLambda(11, 22);
//	string sum = returningLambda(11, 22);
	cout << "The result is " << sum << endl;
	
	// Lambda returning a value, with return type omitted
	auto returningLambda2 = [](int a, int b) { return a + b; };
	sum = returningLambda2(11, 22);
	cout << "The result is " << sum << endl;
	
	// Lambda capturing a variable by value
	double data = 1.23;
	auto capturingVLambda = [data]{
//		data = 10;
		cout << "Data = " << data << endl;
	};
	capturingVLambda();
	
	// Lambda capturing a variable by value
	auto capturingVLambda2 = [data] () mutable {
		data *= 2;
		cout << "Data = " << data << endl;
	};
	capturingVLambda2();	// data not change
	
	// Lambda capturing a variable by reference
	auto capturingRLambda = [&data]{ data *= 2; };	// data real change
	capturingRLambda();
	cout << "Data = " << data << endl;
	cout << "" << endl;
}

void ch_17_2_2(){
	vector<int> ints{ 11, 55, 101, 200 };
	vector<double> doubles{ 11.1, 55.5, 200.2 };
	
	// Define a generic lambda to find values > 100.
	auto isGreaterThan100 = [](auto i){ return i > 100; };
	
	// Use the generic lambda with the vector of integers.
	auto it1 = find_if(cbegin(ints), cend(ints), isGreaterThan100);
	if (it1 != cend(ints)) {
		cout << "Found a value > 100: " << *it1 << endl;
	}
	
	// Use exactly the same generic lambda with the vector of doubles.
	auto it2 = find_if(cbegin(doubles), cend(doubles), isGreaterThan100);
	if (it2 != cend(doubles)) {
		cout << "Found a value > 100: " << *it2 << endl;
	}
	
	cout << "" << endl;
}

void ch_17_2_3(){
	double pi = 3.14;
	auto myLambda = [myCapture = "Pi: ", pi]{
//		pi = 100;
//		myCapture = "PI : ";
		cout<< "myLambda : " << myCapture << pi <<endl;
	};
	myLambda();
	
	auto myPtr = std::make_unique<double>(3.14);
	auto myLambda_02 = [p = move(myPtr)]{
		*p = 10;
		cout<< "myLambda_02 : " << *p <<endl;
	};
	myLambda_02();
//	cout<< "myLambda_02 (after) : " << *myPtr <<endl;	// crash (why -> move)

	
	auto myPtr_03 = std::make_unique<double>(3.14);
	auto myLambda_03 = [myPtr_03 = move(myPtr_03)]{
		*myPtr_03 = 12;
		cout<< "myLambda_03 : " << *myPtr_03 <<endl;
	};
	myLambda_03();
//	cout<< "myLambda_03 (after) : " << *myPtr_03 <<endl;	// crash (why -> move)
	
	cout << "" << endl;
}

function<int(void)> multiplyBy2Lambda(int x){
//	return [x]{ return 2 * x; };
	return [&]{
		return 2 * x;
	};
}

auto multiplyBy2Lambda_cpp14(int x){
//	return [x]{ return 2 * x; };
	return [&]{
		return 2 * x;
	};
}

void ch_17_2_4(){
	function<int(void)> fn = multiplyBy2Lambda(5);
	cout << fn() << endl;
	
	auto fn2 = multiplyBy2Lambda_cpp14(5);
	cout << fn2() << endl;
	
	cout << "" << endl;
}

void testCallback(const vector<int>& vec, const function<bool(int)>& callback){
	
	// Using range-based for loop
	for (const auto& i : vec) {
		if (!callback(i)) {
			break;
		}
		cout << i << " ";
	}
	
	// Using normal for loop
//	for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter) {
//	    if (!callback(*iter)) {
//	        break;
//	    }
//	    cout << *iter << " ";
//	}
	
	cout << endl;
}
void ch_17_2_5(){
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	testCallback(vec, [](int i){return i < 6; });
	
	cout << "" << endl;
}

void ch_17_main(){
//	ch_17_1_1_find();
//	ch_17_1_1_find_if();
//	ch_17_1_2();
//	ch_17_2_1();
//	ch_17_2_2();
//	ch_17_2_3();
//	ch_17_2_4();
	ch_17_2_5();
	cout << "" << endl;
}
