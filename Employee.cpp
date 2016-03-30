//
//  Employee.cpp
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 3/17/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#include "Employee.h"
#include "utilities.h"

Employee::Employee(void){
    employeeName = "Last, First\n";
    employeeNumber = 0;
    hireDate = "1/1/1980";
}

//Destructor Method --> cannot have any parameters
Employee::~Employee(void){}


//Mutator/Set Methods
bool Employee::setEmployeeName (string theName){
    employeeName = theName;
    return true;
}
void Employee::setEmployeeNumber(double theNumber){
    /*  bool NumberTry = true;
     while (NumberTry == true){
     theNumber = Utilities::inputDouble("Please input your employee number between 1 and 9999.\n", 1, 99999, -999);
     if (theNumber > 0 && theNumber < 9999){
     employeeNumber = theNumber;
     NumberTry = false;
     }//if
     else
     throw invalidEmpNum(theNumber);
     }//while */
    employeeNumber = theNumber;
    return;
}

bool Employee::setHireDate(string theHDate){
    hireDate = "theHDate";
    return true;
}

//Accessor/ Get Methods
string Employee::getEmployeeName(void) const{
    return employeeName;
}
double Employee::getEmployeeNumber(void) const{
    return employeeNumber;
}
string Employee::getHireDate(void) const{
    return hireDate;
}



