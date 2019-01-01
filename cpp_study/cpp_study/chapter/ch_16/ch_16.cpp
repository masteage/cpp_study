//
//  ch_16.cpp
//  ch_16
//
//  Created by taeseongsong on 09/12/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "ch_16.hpp"

template<typename T>
void printVector(const vector<T>& v){
	for (auto& element : v){
		cout << element << " ";
	}
	cout << endl;
}

void ch_16_2_1_2(){
	vector<int> intVector(10, 100);
	vector<string> stringVector(10, "hello");
	vector<int> intVector1({1,2,3,4,5});
	vector<int> intVector2 = {1,2,3,4,5};
	vector<int> intVector3{1,2,3,4,5};
	
	vector<int> intVector4(10);
	intVector4.assign(5, 100);
	intVector4.assign({ 1, 2, 3, 4 });
	
	vector<int> vectorOne(10);
	vector<int> vectorTwo(5, 100);
	vectorOne.swap(vectorTwo);
	
	vector<int> vector5(10);//,51);
	vector<int> vector6(10);//,51);
	
	if (vector5 == vector6) {
		cout << "equal!" << endl;
	} else {
		cout << "not equal!" << endl;
	}
	vector5[3] = 50;
	
	if (vector5 == vector6) {
		cout << "equal!" << endl;
	}
	else if (vector5 < vector6) {
		cout << "vector5 is less than vector6" << endl;
	}
	else if (vector5 > vector6) {
		cout << "vector5 is not less than vector6" << endl;
	}
	
	vector<double> doubleVector;
	
//	doubleVector.insr
	
	double max = -numeric_limits<double>::infinity();
//	for (size_t i = 1; true; i++) {
//		double temp;
//		cout << "Enter score " << i << " (-1 to stop): ";
//		cin >> temp;
//		if (temp == -1) {
//			break;
//		}
//		doubleVector.push_back(temp);
//		if (temp > max) {
//			max = temp;
//		}
//	}
	vector<double> vTestValues(10,85);
	vTestValues[3] = 70;
	vTestValues[6] = 90;
	doubleVector = vTestValues;
	max = 90;
	
	
	max /= 100.0;
	for (
//		 vector<double>::iterator iter = begin(doubleVector);
		 auto iter = begin(doubleVector);
		 iter != end(doubleVector);
		 ++iter /*iter++*/
		)
	{
		*iter /= max;
		cout << *iter << endl;
	}
	cout << endl;
	
	// string
	stringVector.assign(10, "hello");
	for (auto it = stringVector.begin(); it != stringVector.end(); ++it) {
		it->append(" there");
	}
	for(auto& str : stringVector){cout << str << endl;}
	cout << endl;
	
	stringVector.assign(10, "my");
	for(auto& str : stringVector){
		str.append(" append");
	}
	for(auto& str : stringVector){cout << str << endl;}
	cout << endl;
	
	stringVector.assign(10, "hello");
	for (auto iter = begin(stringVector); iter != end(stringVector); ++iter) {
		*iter = "not hello";
		cout << *iter << endl;
	}
	cout << endl;
	
	stringVector.assign(10, "hello");
	for (auto iter = cbegin(stringVector); iter != cend(stringVector); ++iter) {
//	for (auto iter = stringVector.cbegin(); iter != stringVector.cend(); ++iter) {
//		*iter = "not hello";
		cout << *iter << endl;
	}
	
	for (const auto& element : stringVector) {
//		*element = "not hello";
		cout << element << endl;
	}
	
	
	vector<int> intVector7;
	auto iter = end(intVector7);
//	*iter = 10;	// exc_bad_access
	iter = begin(intVector7);
//	*iter = 10;

	// infinity loop
//	vector<int> vectorOne_02(10,100);
//	vector<int> vectorTwo_02(10,200);
//	for (auto iter = begin(vectorTwo_02); iter != end(vectorOne_02); ++iter) {
//	}
	
	vector<int> intVector8(10);
	auto it = begin(intVector8);	// [0]
	it += 5;	// [5]
	--it;		// [4]
	*it = 4;	// [4] = 4
	
	cout << "" << endl;
}

void ch_16_2_1_2_AddRemove(){
	vector<int> vectorOne = { 1, 2, 3, 5 };
	vector<int> vectorTwo;
	
	// Oops, we forgot to add 4. Insert it in the correct place
	vectorOne.insert(cbegin(vectorOne) + 3, 4);
	
	// Add elements 6 through 10 to vectorTwo
	for (int i = 6; i <= 10; i++) {
		vectorTwo.push_back(i);
	}
	
	printVector(vectorOne);
	printVector(vectorTwo);
	
	// Add all the elements from vectorTwo to the end of vectorOne
	vectorOne.insert(cend(vectorOne), cbegin(vectorTwo), cend(vectorTwo));
	printVector(vectorOne);
	
	// Now erase the numbers 2 through 5 in vectorOne
	vectorOne.erase(cbegin(vectorOne) + 1, cbegin(vectorOne) + 5);
	printVector(vectorOne);
	
	// Clear vectorTwo entirely
	vectorTwo.clear();
	
	// And add 10 copies of the value 100
	vectorTwo.insert(cbegin(vectorTwo), 10, 100);
	vectorTwo.pop_back();
	printVector(vectorTwo);
	cout << "" << endl;
}

vector<int> createVectorOfSize(size_t size){
	vector<int> vec(size);
	int contents = 0;
	for (auto& i : vec) {
		i = contents++;
	}
	return vec;	// 이동 시맨틱이 없다면 복사 생성자 호출
}

class Element
{
public:
	Element(int i, const string& str) : mI(i), mStr(str) {
		cout << "dd " << endl;
	}
	
private:
	int mI;
	string mStr;
};

void ch_16_2_1_2_MoveSemantics(){
	vector<int> myVector;
	myVector = createVectorOfSize(123);	// 이동 시맨틱이 없다면 복사 생성자 호출
	
	
	vector<Element> vec;
	
	// copy consturct
	Element myElement(12, "Twelve");
	vec.push_back(myElement);
	
	// move semantics
	vec.push_back(move(myElement));
	vec.push_back(Element(12, "Twelve"));
	vec.push_back({12, "Twelve"});
	
	// emplace
	vec.emplace_back(12, "Twelve");
}


void fixedSizeVector ()
{
	vector<double> doubleVector (10);
	auto max = -numeric_limits<double>::infinity ();
	
	for (auto i = 0; i < doubleVector.size (); i++)
	{
		cout << "EnterScore " << i + 1 << " : ";
		cin >> doubleVector[i];
		if (doubleVector[i] > max)
		{
			max = doubleVector[i];
		}
	}
	
	max /= 100.0;
	for (auto& element : doubleVector)
	{
		element /= max;
		cout << element << " ";
	}
}

void dynamicSizeVector ()
{
	vector<double> doubleVector (10);
	auto max = -numeric_limits<double>::infinity ();
	
	for (auto i = 1; true; i++)
	{
		double temp;
		cout << "EnterScore " << i << " (-1 to Step) : ";
		cin >> temp;
		if (temp == -1)
			break;
		
		doubleVector.push_back (temp);
		if (temp > max)
			max = temp;
	}
	
	max /= 100.0;
	for (auto& element : doubleVector)
	{
		element /= max;
		cout << element << " ";
	}
}

void deepVector ()
{
	vector<int> intVector; // size = 0 type = int // defaultVector
	vector<int> intVector2 (10, 100); // size = 10, initialize = 100;
	vector<string> stringVector (10, "hello");
	vector<int> intVector3 ({1, 2, 3, 4, 5, 6});
	intVector3.assign (3, 123);
	intVector3.swap (intVector2);
	for (auto& i : intVector3)
	{
		cout << i << endl;
	}
}

void compareVector ()
{
	vector<int> vectorOne (10);
	vector<int> vectorTwo (10);
	
	if (vectorOne == vectorTwo)
		cout << "equal!" << endl;
	else
		cout << "not equal!" << endl;
	
	vectorOne[3] = 50;
	
	if (vectorOne < vectorTwo)
		cout << "vectorOne is less than vectorTwo" << endl;
	else
		cout << "vectorOne is not less than vectorTwo" << endl;
}

void iteratorVector ()
{
	vector<double> doubleVector (10);
	auto max = -numeric_limits<double>::infinity ();
	
	for (auto i = 1; true; i++)
	{
		double temp;
		cout << "EnterScore " << i << " (-1 to Step) : ";
		cin >> temp;
		if (temp == -1)
			break;
		
		doubleVector.push_back (temp);
		if (temp > max)
			max = temp;
	}
	
	max /= 100.0;
	
	//for (vector<double>::iterator iter = begin (doubleVector); iter != end (doubleVector); ++iter)
	for(auto iter = doubleVector.begin(); iter != doubleVector.end(); ++iter)
	{
		*iter /= max;
		cout << *iter << " ";
	}
}

void iteratorVector2 ()
{
	vector<string> stringVector (10, "hello");
	for (auto& str : stringVector)
		str.append (" there");
}

//class Element
//{
//public:
//	Element (int i, const string& str) : mI (i), mStr (str)
//	{}
//
//private:
//	int mI;
//	string mStr;
//};

void MovePushback()
{
	vector<Element> vec;
	
	Element myElement (12, "Twelve");
	vec.push_back (myElement);
	
	vec.push_back (move (myElement));
	vec.push_back (Element (12, "Twelve"));
	vec.push_back ({12, "Twelve"});
}

void RoundRobin ()
{
	
}

void ch_16_main(){
//	ch_16_2_1_2();
//	ch_16_2_1_2_AddRemove();
//	ch_16_2_1_2_MoveSemantics();
	cout << "" << endl;
}
