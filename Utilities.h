//
//  utilities.h
//  utilities
//
//  Created by Marcela Vazquez on 2/3/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

//
//  utilities.h
//  CPPUtilities
//
//  Created by Bill Komanetsky on 1/29/15.
//  Copyright (c) 2015 Bill Komanetsky. All rights reserved.
//

#ifndef __CPPUtilities__utilities__
#define __CPPUtilities__utilities__

#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

//
//Prototypes for utilities.cpp
//
class Utilities{
private:
    
public:
    
    static string makeUpperCase(string);
    static string makeLowerCase(string);
    static void clearCIN(void);
    static string inputString(string, int, int);
    static int inputInt(string, int, int, int);
    static double inputDouble(string, double, double, double);
    static string centerString(string, int);
    static int getRandomInt(int, int);
    static double getRandomDouble(int, int, int);
    static bool verifyAction(string);
    static char askOverWrite(void);
    static string getRandomString(int, int);
};


#endif /* defined(__CPPUtilities__utilities__) */
