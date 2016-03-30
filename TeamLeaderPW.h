//
//  TeamLeaderPW.h
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 3/18/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#ifndef __Ch_15_Asst__TeamLeaderPW__
#define __Ch_15_Asst__TeamLeaderPW__

#include "ProductionWorker.h"
#include <iostream>
#include "utilities.h"
#include <stdio.h>
using namespace std;

class TeamLeader : public ProductionWorker{
private:
    double requiredT_hours;
    double attendedT_hours;
    double monthlyBonus;
public:
    TeamLeader();
    ~TeamLeader();
    
    bool setRequiredT_hours();
    bool setAttendedT_hours();
    bool setMonthlyBonus();
    
    double getRequiredT_hours(void) const;
    double getAttendedT_hours(void) const;
    double getMonthlyBonus(void) const;
    
    //virtual pay function
    //virtual double payEmployee();
    
};

#endif /* defined(__Ch_15_Asst__TeamLeaderPW__) */
