//
//  ProductionWorker.h
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 3/17/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#ifndef __Ch_15_Asst__ProductionWorker__
#define __Ch_15_Asst__ProductionWorker__

#include <stdio.h>
#include "Employee.h"
#include "utilities.h"

class ProductionWorker : public Employee{
private:
    int shift;
    double hourlyRate;
    double hoursWorked;
public:
    //default constructor
    ProductionWorker(void);
    //destructor
    ~ProductionWorker(void);
    //intialized constructors
    
    class invalidShift{
    private:
        int badShift;
    public:
        invalidShift(int bS){
            badShift = bS;
        }
        int getbSValue() const{
            return badShift;
        };
    };//invalid shift
    
    class invalidPayRate{
    private:
        double badRate;
    public:
        invalidPayRate(double bR){
            badRate = bR;
        }
        double getbRValue() const{
            return badRate;
        }//getbRValue
        
    };//invalid payrate
    
    //Mutator/Set Methods
    void setShift(int);
    void setHourlyRate(double);
    bool setHoursWorked(double);
    
    //Accessor/ Get Methods
    int getShift(void) const;
    double getHourlyRate(void) const;
    double getHoursWorked(void) const;
    
    //virtual pay function
    virtual double payEmployee();
    
};

#endif /* defined(__Ch_15_Asst__ProductionWorker__) */
