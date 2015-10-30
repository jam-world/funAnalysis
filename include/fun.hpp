//
//  fun.hpp
//  funTab
//
//  Created by chencha on 10/30/15.
//  Copyright © 2015 jam-world. All rights reserved.
//

#ifndef fun_hpp
#define fun_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "var.hpp"
using namespace std;

class fun {
private:
    string mReturnType;
    vector<var*> mVarTable;
public:
    void addVar(string name,string type); // add variable
    void setReturnType(string type); // set the return type
    void print(); // pritn the function
    bool isFunSame(fun* another); // test is the function same as another
    int paraNum() {return mVarTable.size();} // return paraNum
    string getReturnType() {return mReturnType;} // get the return type
    string getIthVarType(int i) {return mVarTable[i]->getType();} // get the i-th element type;
};

#endif /* fun_hpp */
