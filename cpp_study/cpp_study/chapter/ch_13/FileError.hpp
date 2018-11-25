//
//  FileError.hpp
//  ch_13
//
//  Created by taeseongsong on 25/11/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#ifndef FileError_hpp
#define FileError_hpp

#pragma mark - FileError
class FileError : public exception//runtime_error
{
public:
//	Constructor for 'FileError' must explicitly initialize the base class 'std::runtime_error' which does not have a default constructor
	FileError(const string& fileIn) : mFile(fileIn) {}
//	FileError(const string& fileIn) : runtime_error(""), mFile(fileIn) {}
	virtual const char* what() const noexcept override { return mMsg.c_str(); }
	const string& getFileName() { return mFile; }
	
protected:
	void setMessage(const string& message) { mMsg = message; }
	
private:
	string mFile, mMsg;
};

#pragma mark - FileOpenError
class FileOpenError : public FileError
{
public:
	FileOpenError(const string& fileNameIn);
};

#pragma mark - FileReadError
class FileReadError : public FileError
{
public:
	FileReadError(const string& fileNameIn, int lineNumIn);
	int getLineNum() { return mLineNum; }
	
private:
	int mLineNum;
};

#pragma mark -
#endif /* FileError_hpp */
