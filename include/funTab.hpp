//
//  funTab.hpp
//  funTab
//
//  Created by chencha on 10/30/15.
//  Copyright © 2015 jam-world. All rights reserved.
//

#ifndef funTab_hpp
#define funTab_hpp

#include <stdio.h>
#include <map>
#include <string>
#include "fun.hpp"
using namespace std;

class funTab {
private:
    map<string, fun*> mFunTable;
public:
    void addFun(string name, fun* funVar); // add new function
    bool isFunExist(string name); // test is the function exist, exist return true, otherwise return false
    fun* getFun(string name) {return mFunTable[name];} // get the function
    void print(); // print the table
};


#endif /* funTab_hpp */
