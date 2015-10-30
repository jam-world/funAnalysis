//
//  var.hpp
//  funTab
//
//  Created by chencha on 10/30/15.
//  Copyright © 2015 jam-world. All rights reserved.
//

#ifndef var_hpp
#define var_hpp

#include <stdio.h>
#include <string>
using namespace std;

class var {
private:
    string mType;
    string mName;
public:
    var(string name, string type):mType(type),mName(name) {} // constructor
    string getType() {return mType;} // get the variable type
    string getName() {return mName;} // get the variable name
};

#endif /* var_hpp */
