//
//  Employee.h
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 3/17/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#ifndef __Ch_15_Asst__Employee__
#define __Ch_15_Asst__Employee__

#include <stdio.h>
#include <string>
#include "utilities.h"

using namespace std;

class Employee{
private:
    string employeeName;
    double employeeNumber;
    string hireDate;
    
public:
    //Constructor/Destructor Methods
    Employee (void);
    ~Employee(void);
    
    //Mutator/Set Methods
    bool setEmployeeName(string);
    void setEmployeeNumber(double);
    bool setHireDate(string);
    
    class invalidEmpNum{
    private:
        int badEmpNum;
    public:
        invalidEmpNum(int bEN){
            badEmpNum = bEN;
        }
        int getbENum() const{
            return badEmpNum;
        };
    };//invalid employee number
    
    //Accessor/ Get Methods
    string getEmployeeName(void) const;
    double getEmployeeNumber(void) const;
    string getHireDate(void) const;
    
    //virtual pay function
    //all pay is done weekly
    virtual double payEmployee() = 0;
};


#endif /* defined(__Ch_15_Asst__Employee__) */
