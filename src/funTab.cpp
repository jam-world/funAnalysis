//
//  funTab.cpp
//  funTab
//
//  Created by chencha on 10/30/15.
//  Copyright © 2015 jam-world. All rights reserved.
//

#include "funTab.hpp"
#include <iostream>

void funTab::addFun(string name, fun* funVar) {
    mFunTable[name]=funVar;
}

bool funTab::isFunExist(string name) {
    return mFunTable.find(name)!=mFunTable.end()?true:false;
}

void funTab::print() {
    map<string, fun*>::iterator iter;
    for (iter=mFunTable.begin(); iter!=mFunTable.end(); iter++) {
        cout << "Function: " << iter->first << endl;
        iter->second->print();
    }
}