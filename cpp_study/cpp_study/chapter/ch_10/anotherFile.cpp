//
//  anotherFile.cpp
//  cpp_study
//
//  Created by taeseongsong on 21/10/2018.
//  Copyright © 2018 taeseongsong. All rights reserved.
//

extern int extern_x = 3;
extern int extern_y;
int extern_y = 10;

static void f();
void f(){
	cout << "f call" << endl;
}
