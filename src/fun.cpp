//
//  fun.cpp
//  funTab
//
//  Created by chencha on 10/30/15.
//  Copyright © 2015 jam-world. All rights reserved.
//

#include "fun.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

void printVar(var* tVar) {
    cout << tVar->getName() << " (" << tVar->getType() << "),";
}


void fun::addVar(string name, string type) {
    var *newVar = new var(name,type);
    mVarTable.push_back(newVar);
}


void fun::setReturnType(string type) {
    mReturnType=type;
}

void fun::print() {
    cout << "Type: " << mReturnType << endl;
    cout << "Arguments: ";
    for_each(mVarTable.begin(), mVarTable.end(), printVar);
    cout << endl;
}

bool fun::isFunSame(fun* another) {
    if (mReturnType!=another->getReturnType()) {
        cout << "return type does not match" << endl;
        return false;
    } else if (paraNum()!=another->paraNum()) {
        cout << "parameter number dose not match" << endl;
        return false;
    } else {
        int i = 0;
        while (i!=mVarTable.size()) {
            if (getIthVarType(i)!=another->getIthVarType(i)) {
                cout << "parameter list does not match" << endl;
                return false;
            }
            i++;
        }
    }
    return true;
}