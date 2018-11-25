//
//  FileError.cpp
//  ch_13
//
//  Created by taeseongsong on 25/11/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#include "FileError.hpp"

#pragma mark - FileOpenError
FileOpenError::FileOpenError(const string& fileNameIn) : FileError(fileNameIn){
	setMessage("Unable to open " + fileNameIn);
}

#pragma mark - FileReadError
FileReadError::FileReadError(const string& fileNameIn, int lineNumIn) :
FileError(fileNameIn), mLineNum(lineNumIn){
	ostringstream ostr;
	
	ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
	setMessage(ostr.str());
}

#pragma mark -
