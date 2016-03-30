//
//  ShiftSupervisor.h
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 3/18/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#ifndef __Ch_15_Asst__ShiftSupervisor__
#define __Ch_15_Asst__ShiftSupervisor__

#include <stdio.h>

#include <stdio.h>
#include "Employee.h"
#include "utilities.h"

class ShiftSupervisor : public Employee{
private:
    double yearlySalary;
    double EOYbonus;
public:
    ShiftSupervisor();
    ~ShiftSupervisor();
    
    bool setYearlySalary();
    bool setEOYbonus();
    
    double getYearlySalary(void) const;
    double getEOYbonus(void) const;
    
    //virtual pay function
    virtual double payEmployee();
    
};

#endif /* defined(__Ch_15_Asst__ShiftSupervisor__) */
