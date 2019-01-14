//
//  ch_20.cpp
//  ch_20
//
//  Created by taeseongsong on 14/01/2019.
//  Copyright © 2019 taeseongsong. All rights reserved.
//

#include "ch_20.hpp"

void ch_20_2_1(){
	vector<int> myVector;
	myVector.push_back(11);
	myVector.push_back(22);	// it1 - forward 1
	myVector.push_back(33);
	myVector.push_back(44);
	myVector.push_back(22);	// it2 - forward 4 , backward 2
	myVector.push_back(99);
	myVector.push_back(11);
	
	int num = 22;
	auto it1 = find(begin(myVector), end(myVector), num);
	auto it2 = find(rbegin(myVector), rend(myVector), num);
	if (it1 != end(myVector)) {
		
		// 앞에서 부터
		cout << "Found " << num << " at position " << it1 - begin(myVector) << " going forward." << endl;
		cout << "Found " << num << " at position " << it2.base() - 1 - begin(myVector) << " going backward." << endl;
		
		// 뒤에서 부터.
		cout << "Found " << num << " at position " << it2 - rbegin(myVector) << " going backward." << endl;
//		cout << "Found " << num << " at position " << rbegin(myVector) - it2 << " going backward." << endl;
//		cout << "Found " << num << " at position " << rbegin(myVector).base() - 1 - it2 << " going backward." << endl;
	} else {
		cout << "Failed to find " << num << endl;
	}
}

#include <numeric>
void ch_20_2_2(){
	vector<int> myVector(10);
	
	// http://www.cplusplus.com/reference/numeric/iota/
	iota(begin(myVector), end(myVector), 1);
	copy(cbegin(myVector), cend(myVector), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "" << endl;
	
	
	istream_iterator<int> numbersIter(cin);
	istream_iterator<int> endIter;
	int sum = accumulate(numbersIter, endIter, 0);
	cout << "Sum: " << sum << endl;
	cout << "" << endl;
}

void ch_20_2_3(){
	vector<int> vectorOne, vectorTwo, vectorThree;
	vectorOne.push_back(1);
	vectorOne.push_back(2);
	vectorOne.push_back(3);
	vectorOne.push_back(4);
	vectorOne.push_back(100);
	vectorOne.push_back(101);
	vectorOne.push_back(102);
	vectorOne.push_back(90);
	
	// back_insert_iterator
	back_insert_iterator<vector<int>> my_back_inserter(vectorTwo);
	remove_copy_if(cbegin(vectorOne), cend(vectorOne), my_back_inserter, [](int i){ return i == 100; });
	
	// bind2nd
//	remove_copy_if(vectorOne.begin(), vectorOne.end(), my_back_inserter, bind2nd(equal_to<int>(), 100));
	
	// insert_iterator
//	insert_iterator<vector<int>> inserter(vectorTwo,begin(vectorTwo));
//	remove_copy_if(cbegin(vectorOne), cend(vectorOne), inserter, [](int i){ return i == 100; });
	
	
	copy(cbegin(vectorTwo), cend(vectorTwo), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	// three
	remove_copy_if(cbegin(vectorOne), cend(vectorOne), back_inserter(vectorThree), [](int i){ return i >= 100; });
	copy(cbegin(vectorThree), cend(vectorThree), ostream_iterator<int>(cout, " "));
	cout << endl;
	
}

#include <set>
void ch_20_2_3_set(){
	vector<int> vectorOne;
	set<int> setOne;
	vectorOne.push_back(1);
	vectorOne.push_back(2);
	vectorOne.push_back(3);
	vectorOne.push_back(4);
	vectorOne.push_back(100);
	vectorOne.push_back(101);
	vectorOne.push_back(102);
	vectorOne.push_back(90);
	
	insert_iterator<set<int>> inserter(setOne, begin(setOne));
	remove_copy_if(cbegin(vectorOne), cend(vectorOne), inserter, [](int i){ return i == 100; });
	copy(cbegin(setOne), cend(setOne), ostream_iterator<int>(cout, " "));
	cout << endl;
}

class MoveableClass{
public:
	int value = 0;
public:
	MoveableClass() {
		cout << "Default constructor" << endl;
	}
	MoveableClass(const MoveableClass& /* src */) {
		cout << "Copy constructor" << endl;
	}
	MoveableClass(MoveableClass&& /* src */) noexcept {
		cout << "Move constructor" << endl;
	}
	MoveableClass& operator=(const MoveableClass& /* rhs */) {
		cout << "Copy assignment operator" << endl;
		return *this;
	}
	MoveableClass& operator=(MoveableClass&& /* rhs */) noexcept {
		cout << "Move assignment operator" << endl;
		return *this;
	}
};

void ch_20_2_4(){
	vector<MoveableClass> vecSource,vecSource_02;
	cout << "----" << endl;
	cout << "MoveableClass mc" << endl;
	MoveableClass mc;
	cout << "----" << endl;
	cout << "vecSource push back" << endl;
	vecSource.push_back(mc);
	vecSource.push_back(mc);
	cout << "----" << endl;
	cout << "vecSource_02 push back" << endl;
	vecSource_02.push_back(mc);
	vecSource_02.push_back(mc);
	cout << "----" << endl;
	
	// Copy the elements from vecSource to vecOne
	cout << "vecOne" << endl;
	vector<MoveableClass> vecOne(cbegin(vecSource), cend(vecSource));
	cout << "----" << endl;
	
	
	// Move the elements from vecSource to vecTwo
	(*begin(vecSource)).value = 10;
	cout << "vecTwo" << endl;
	vector<MoveableClass> vecTwo(make_move_iterator(begin(vecSource)),
								 make_move_iterator(end(vecSource)));
	cout << "----" << endl;
	cout << "vecThree" << endl;
//	vector<MoveableClass> vecThree(2);	// Default constructor
	vector<MoveableClass> vecThree;
//	vecThree.resize(2);					// Default constructor
	vecThree.reserve(2);
	
	// Copy assignment operator
//	copy(cbegin(vecSource_02), cend(vecSource_02), begin(vecThree));
	
	// Move assignment operator
	copy(make_move_iterator(begin(vecSource_02)), make_move_iterator(end(vecSource_02)), make_move_iterator(begin(vecThree)));
//	move(begin(vecSource_02), end(vecSource_02), begin(vecThree));
//	move(make_move_iterator(begin(vecSource_02)), make_move_iterator(end(vecSource_02)), make_move_iterator(begin(vecThree)));
	cout << "----" << endl;
}

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator find_all(InputIterator first, InputIterator last, OutputIterator dest, Predicate pred){
	while (first != last) {
		if (pred(*first)) {
			*dest = first;
			++dest;
		}
		++first;
	}
	return dest;
}
void ch_20_3_2_1(){
	vector<int> vec{ 3, 4, 5, 4, 5, 6, 5, 8, 9 ,2 };
	vector<vector<int>::iterator> matches;
	find_all(begin(vec), end(vec), back_inserter(matches), [](int i){ return i == 5; });
//	find_all(begin(vec), end(vec), inserter(matches,begin(matches)), [](int i){ return i == 5; });
	cout << "Found " << matches.size() << " matching elements: " << endl;
	for (auto it : matches) {
		cout << *it << " at position " << (it - cbegin(vec)) << endl;
	}
	cout << endl;
}

template <typename IteratorType>
void iteratorTraitsTest(IteratorType it){
	typename std::iterator_traits<IteratorType>::value_type temp;
	temp = *it;
//	auto temp = *it;
	cout << temp << endl;
}

void ch_20_3_2_2(){
	vector<int> v{ 5 };
	iteratorTraitsTest(cbegin(v));
}

/*
#include "hash_map_01.h"
using namespace ProCpp_01;

void hash_map_01(){
	hash_map<int, int> myHash;
	myHash.insert(make_pair(4, 40));
	myHash.insert(make_pair(6, 60));
	
	// x will have type hash_map<int, int>::value_type*
	auto x = myHash.find(4);
	if (x != nullptr) {
		cout << "4 maps to " << x->second << endl;
	} else {
		cout << "cannot find 4 in map" << endl;
	}
	
	myHash.erase(4);
	
	auto x2 = myHash.find(4);
	if (x2 != nullptr) {
		cout << "4 maps to " << x2->second << endl;
	} else {
		cout << "cannot find 4 in map" << endl;
	}
	
	myHash[4] = 35;
	myHash[4] = 60;
	
	auto x3 = myHash.find(4);
	if (x3 != nullptr) {
		cout << "4 maps to " << x3->second << endl;
	} else {
		cout << "cannot find 4 in map" << endl;
	}
	
	
	hash_map<int, int> myHash2;
	myHash2 = myHash;
	hash_map<int, int> myHash3(myHash2);
}
*/


#include <map>
#include "hash_map_02.h"
using namespace ProCpp_02;

void hash_map_02(){
	//hash_map<string, int> myHash;
	//myHash.insert(make_pair("KeyOne", 100));
	//myHash.insert(make_pair("KeyTwo", 200));
	//myHash.insert(make_pair("KeyThree", 300));
	
	hash_map<string, int> myHash{
		{ "KeyOne", 100 },
		{ "KeyTwo", 200 } };
	
	myHash.insert({
		{ "KeyThree", 300 },
		{ "KeyFour", 400 } });
	
	for (auto it = myHash.cbegin(); it != myHash.cend(); ++it) {
		// Use both -> and * to test the operations
		cout << it->first << " maps to " << (*it).second << endl;
	}
	
	cout << "----" << endl;
	
	auto found = myHash.find("KeyThree");
	if (found != end(myHash))
	{
		cout << "Found KeyThree: value = " << found->second << endl;
	}
	
	cout << "----" << endl;
	
	// Print elements using range-based for loop
	for (auto& p : myHash) {
		cout << p.first << " maps to " << p.second << endl;
	}
	
	cout << "----" << endl;
	
	// Create a map with all the elements in the hashmap
	map<string, int> myMap(cbegin(myHash), cend(myHash));
	for (auto& p : myMap) {
		cout << p.first << " maps to " << p.second << endl;
	}
	
	hash_map<string, int> myHash2;
	myHash.swap(myHash2);
	
	hash_map<string, int> myHash3(std::move(myHash2));
	
	cout << myHash3.size() << endl;
	cout << myHash3.max_size() << endl;
}

void ch_20_main(){
//	ch_20_2_1();
//	ch_20_2_2();
//	ch_20_2_3();
//	ch_20_2_3_set();
//	ch_20_2_4();
//	ch_20_3_2_1();
//	ch_20_3_2_2();
//	hash_map_01();
	hash_map_02();
	cout << "" << endl;
}
