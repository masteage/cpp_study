//
//  ch_12.cpp
//  ch_12
//
//  Created by taeseongsong on 04/11/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "ch_12.hpp"

void ch_12_1_3_1(){
	int i = 7;
	cout << i << endl;
	
	char ch = 'a';
	cout << ch << endl;
	
	string myString = "Hello World.";
	cout << myString << endl;
	
	int j = 11;
	cout << "The value of j is " << j << "!" << endl;
	
//	cout << "Line 1" << endl << "Line 2" << endl << "Line 3" << endl;
	cout << "Line 1\nLine 2\nLine 3" << endl;
}

void rawWrite(const char* data, size_t dataSize){
	cout.write(data, dataSize);
}

void rawPutChar(const char* data, size_t charIndex){
	cout.put(data[charIndex]);
}

void ch_12_1_3_2(){
	const char* cpRawWrite = "raw write test\n";
	rawWrite(cpRawWrite,strlen(cpRawWrite));
	
	const char* cpRawPut = "raw put test\n";
	rawPutChar(cpRawPut,4);
	
	// http://www.cplusplus.com/reference/ostream/flush-free/
	cout << "abc";
	cout.flush();
	cout << "def";
	cout << endl;
}

void ch_12_1_3_3(){
	if(cout.good()){
		cout << "All good" << endl;
	}
	
	cout.flush();
	if(cout.fail()){
		cout << "dd" << endl;
	}
	
	
	
	class myException: public exception{
	public:
		myException(string what){strWhat = what;}
		
	private:
		string strWhat = "";
		virtual const char* what() const throw(){
			return strWhat.c_str();
		}
	};
	
	cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
	try {
		cout << "Hello World." << endl;
		throw myException("my custom error");
//		throw ios_base::failure("ios_base::failure - my call");
	}
	catch (const exception& e){
		cerr << "Caught exception: " << e.what() << endl;
	}
//	catch (const ios_base::failure& ex) {
//		cerr << "Caught exception: " << ex.what() << ", error code = " << ex.code() << endl;
//	}
	
	cout.clear();
}

#include <iomanip>
void ch_12_1_3_4(){
	// Boolean values
	bool myBool = true;
	cout << "This is the default: " << myBool << endl;
	cout << "This should be true: " << boolalpha << myBool << endl;
	cout << "This should be 1: " << noboolalpha << myBool << endl;
	
	// Simulate "%6d" with streams
	int i = 123;
	printf("This should be '   123': %6d\n", i);
	cout << "This should be '   123': " << setw(6) << i << endl;
	
//	http://www.cplusplus.com/reference/iomanip/setfill/
//	http://www.cplusplus.com/reference/ios/basic_ios/fill/
	char prevFill = '\0';
	prevFill = cout.fill();
	// Simulate "%06d" with streams
	printf("This should be '000123': %06d\n", i);
	cout << "This should be '000123': " << setfill('0') << setw(6) << i << endl;
	
	// Fill with *
	cout << "This should be '***123': " << setfill('*') << setw(6) << i << endl;
	// Reset fill character
//	cout << setfill(' ');
	cout.fill(prevFill);
	
	// Use methods
//	cout.precision(5);
//	cout << "This should be '1.2346': " << 1.23456789 << endl;
	cout << "This should be '1.2346': " << setprecision(5) << 1.23456789 << endl;
	
	// Floating point values
	double dbl = 1.452;
	double dbl2 = 5;
	cout << "This should be ' 5.0000': " << setw(2) << showpoint << dbl2 << endl;
	cout << "This should be ' 5': " << setw(2) << noshowpoint << dbl2 << endl;
	cout << "This should be @@1.452: " << setw(7) << setfill('@') << dbl << endl;
	// Reset fill character
	cout << setfill(' ');
	
	// Instructs cout to start formatting numbers according to your location.
	// Chapter 18 explains the details of the imbue call and the locale object.
//	http://www.cplusplus.com/reference/ios/ios/imbue/
	cout.imbue(locale(""));
	
	// Format numbers according to your location
	cout << "This is 1234567 formatted according to your location: " << 1234567 << endl;
	
	// Money amount
	cout << "This should be a money amount of 120000, "
	<< "formatted according to your location: "
	<< put_money("120000") << endl;
	
	// Date and time
#if !defined(_MSC_VER)
	time_t t_t = time(nullptr);  // Get current system time
	tm* t = localtime(&t_t);     // Convert to local time
	cout << "This should be the current date and time formatted according to your location: "
	<< put_time(t, "%c") << endl;
#else
	// Visual C++:
	time_t t_t = time(nullptr);
	tm t;
	localtime_s(&t, &t_t);
	cout << "This should be the current date and time formatted according to your location: "
	<< put_time(&t, "%c") << endl;
#endif
	
	// C++14: Quoted string
	cout << "This should be: \"Quoted string with \\\"embedded quotes\\\".\": "
	<< quoted("Quoted string with \"embedded quotes\".") << endl;
}

string readName(istream& inStream){
	string name;
	while (!inStream.fail()) {
		int next = inStream.get();
		if (next == std::char_traits<char>::eof())
			break;
		name += static_cast<char>(next);
	}
	return name;
}

string readName_get(istream& inStream){
	string name;
	char next;
	while (inStream.get(next)) {
		name += next;
	}
	return name;
}

void getReservationData(){
	string guestName;
	int partySize;
	cout << "Name and number of guests: ";
	cin >> guestName >> partySize;
	cout << "Thank you, " << guestName << "." << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

void getReservationData_unget(){
	string guestName;
	int partySize = 0;
	char ch;
	// no skip white space
	// http://www.cplusplus.com/reference/ios/noskipws/
	cin >> noskipws;
	
	// read name - until digit
	while (cin >> ch) {
		
		// is digit check
		if (isdigit(ch)) {
			
			// back iostream
			// http://www.cplusplus.com/reference/istream/istream/unget/
			cin.unget();
			// http://www.cplusplus.com/reference/istream/istream/putback/
//			cin.putback(ch);
			
			// check iostream
			if (cin.fail()) cout << "unget() failed" << endl;
			
			// out
			break;
		}
		// name add (char)
		guestName += ch;
	}
	
	// get int
	cin >> partySize;
	
	cout << "Thank you '" << guestName
	<< "', party of " << partySize << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

void getReservationData_peek(){
	string guestName;
	int partySize = 0;
	// Read characters until we find a digit
	char ch;
	cin >> noskipws;
	while (true) {
		// 'peek' at next character
		// http://www.cplusplus.com/reference/istream/istream/peek/
		ch = static_cast<char>(cin.peek());
		if (!cin.good())
			break;
		if (isdigit(ch)) {
			// next character will be a digit, so stop the loop
			break;
		}
		// next character will be a non-digit, so read it
		cin >> ch;
		guestName += ch;
	}
	// Read partysize
	cin >> partySize;
	
	cout << "Thank you '" << guestName
	<< "', party of " << partySize << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

const int kBufferSize = 1024;
void getLine(){
	char buffer[kBufferSize];
	cin.getline(buffer, kBufferSize);
	cout << "***" << buffer << "***" << endl;
	
	string myString;
	std::getline(cin, myString);
	cout << "***" << myString << "***" << endl;
}

void ch_12_1_4_2(){
//	string strRet = readName_get(cin);
//	cout << "readName : " << strRet << endl;
//
//	getReservationData();
//	getReservationData_unget();
//	getReservationData_peek();
//	getLine();
}

#include "Muffin.hpp"
Muffin createMuffin(istringstream& inStream){
	Muffin muffin;
	// Assume data is properly formatted:
	// Description size chips
	
	string description;
	int size;
	bool hasChips;
	
	// Read all three values. Note that chips is represented
	// by the strings "true" and "false"
	inStream >> description >> size >> boolalpha >> hasChips;
	muffin.setSize(size);
	muffin.setDescription(description);
	muffin.setHasChocolateChips(hasChips);
	
	return muffin;
}
void ch_12_1_5(){
	cout << "First, let's create a muffin in code and output it." << endl;
	Muffin m;
	m.setDescription("Giant_Blueberry_Muffin");
	m.setSize(42);
	m.setHasChocolateChips(false);
	m.output();
	
	cout << "Now we'll create a muffin from a string stream" << endl;
	istringstream instream("My_Muffin 2 true");
	Muffin m2 = createMuffin(instream);
	m2.output();
}

#include <fstream>
void ch_12_3(int argc, const char * argv[]){
	ofstream outFile("test.txt", ios_base::trunc);
	if (!outFile.good()) {
		cerr << "Error while opening output file!" << endl;
		return;
	}
	outFile << "There were " << argc << " arguments to this program." << endl;
	cout << "There were " << argc << " arguments to this program." << endl;
	outFile << "They are: " << endl;
	cout << "They are: " << endl;
	for (int i = 0; i < argc; i++) {
		outFile << argv[i] << endl;
		cout << argv[i] << endl;
	}
}

void ch_12_3_1(){
	ofstream fout("test_out.txt");
	if (!fout) {
		cerr << "Error opening test.out for writing" << endl;
		return;
	}
	
	// 1. Output the string "12345".
	fout << "12345";
	
	// 2. Verify that the marker is at position 5.
	ios_base::streampos curPos = fout.tellp();
	if (5 == curPos) {
		cout << "Test passed: Currently at position 5" << endl;
	} else {
		cout << "Test failed: Not at position 5" << endl;
	}
	
	// 3. Move to position 2 in the stream.
	fout.seekp(2, ios_base::beg);
	
	// 4. Output a 0 in position 2 and close the stream.
	fout << 0;
	fout.close();
	
	// 5. Open an input stream on test.out.
	ifstream fin("test_out.txt");
	if (!fin) {
		cerr << "Error opening test.out for reading" << endl;
		return;
	}
	
	// 6. Read the first token as an integer.
	int testVal;
	fin >> testVal;
	
	// 7. Confirm that the value is 12045.
	const int expected = 12045;
	if (testVal == expected) {
		cout << "Test passed: Value is " << expected << endl;
	} else {
		cout << "Test failed: Value is not " << expected
		<< "(it was " << testVal << ")" << endl;
	}
}
		
void ch_12_3_2(){
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	inFile.tie(&outFile);
	outFile << "Hello there!";
	string nextToken;
	inFile >> nextToken;
	cout << nextToken << endl;
}


bool changeNumberForID(const string& inFileName, int inID, const string& inNewNumber)
{
	fstream ioData(inFileName.c_str());
	if (!ioData) {
		cerr << "Error while opening file " << inFileName << endl;
		return false;
	}
	
	// Loop until the end of file
	while (ioData.good()) {
		int id;
		string number;
		
		// Read the next ID.
		ioData >> id;
		
		// Check to see if the current record is the one being changed.
		if (id == inID) {
			// Seek the write position to the current read position
			ioData.seekp(ioData.tellg());
			// Output a space, then the new number.
			ioData << " " << inNewNumber;
			break;
		}
		
		// Read the current number to advance the stream.
		ioData >> number;
	}
	return true;
}

void ch_12_4(){
	cout << "changeNumberForID : " << boolalpha << changeNumberForID("data.txt", 263, "123-333-3333") << endl;
}

void ch_12_main(int argc, const char * argv[]){
	ch_12_1_3_1();
	ch_12_1_3_2();
	ch_12_1_3_3();
	ch_12_1_3_4();
	ch_12_1_4_2();
	ch_12_1_5();
	ch_12_3(argc,argv);
	ch_12_3_1();
	ch_12_3_2();
	ch_12_4();
	cout << "" << endl;
}
