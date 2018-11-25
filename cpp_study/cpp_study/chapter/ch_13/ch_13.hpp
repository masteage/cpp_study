//
//  ch_13.hpp
//  ch_13
//
//  Created by taeseongsong on 25/11/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

#ifndef ch_13_hpp
#define ch_13_hpp

void readIntegerFile_AnyThrow(const string& fileName, vector<int>& dest);
void readIntegerFile_ThrowList(const string& fileName, vector<int>& dest) throw (invalid_argument, runtime_error);
void readIntegerFile_NoExcept(const string& fileName, vector<int>& dest) noexcept;
void readIntegerFile_NoThrow(const string& fileName, vector<int>& dest) throw();
void ch_13_main();

#endif /* ch_13_hpp */
