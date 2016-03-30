//
//  ProductionWorker.cpp
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 3/17/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#include "ProductionWorker.h"
#include <iostream>
#include "utilities.h"
using namespace std;

//Constructor Methods

ProductionWorker::ProductionWorker(void){
    shift = 1;
    hourlyRate = 15.00;
    hoursWorked = 0.;
}

//Destructor Method
ProductionWorker::~ProductionWorker(void){}


//The Productionworker class should throw an exception named invalidPayRate when it receives a negative number for the hourly pay rate.


//Mutator/Set Methods
void ProductionWorker::setShift(int S){
    //shift = Utilities::inputInt("Please enter 1 for day shift or 2 for night shift.\n", -5, 5, -99);
    if (S == 1 || S == 2)
        shift = S;
    else
        throw invalidShift(S);
}
void ProductionWorker::setHourlyRate(double rate){
    //hourlyRate = Utilities::inputDouble("Please input the employee's pay rate.\n", -100, 25.00 , -99);
    if (rate >= 0)
        hourlyRate = rate;
    else
        throw invalidPayRate(rate);
}
//no overtime!
bool ProductionWorker::setHoursWorked(double hours){
    //hoursWorked = Utilities::inputDouble("Please input the employee's hours worked for the week.\n", 0, 40 , -99);
    if (hours > 0 && hours < 40){
        hoursWorked = hours;
        return true;
    }
    else{
        cout << "You may not input over 40 hours for the week.\n";
        return false;
    }
}

//Accessor/ Get Methods
int ProductionWorker::getShift(void) const{
    return shift;
}
double ProductionWorker::getHourlyRate(void) const{
    return hourlyRate;
}
double ProductionWorker::getHoursWorked(void) const{
    return hoursWorked;
}

//virtual pay function
double ProductionWorker::payEmployee(){
    bool shifttry = true, paytry1 = true, paytry2 = true;
    double pay;
    while (shifttry){
        int tempShift = Utilities::inputInt("Please enter 1 for the day shift or 2 for the night shift.\n", 1, 50, -99);
        try{ //shift
            setShift(tempShift);
            switch (shift){
                case 1: { setHoursWorked(Utilities::inputDouble("Enter hours worked.", 0, 40, -999));
                    while (paytry1 == true){
                        double tempRate1 = Utilities::inputDouble("Please input the employee's pay rate.\n",-100, 25.00 , 999);
                        try {//try for pay rate w/ shift 1
                            setHourlyRate(tempRate1);
                            //pay = hoursWorked*hourlyRate;
                            paytry1 = false;
                        }//try for payrate with shift 1
                        catch (invalidPayRate ePR1) {
                            cout << "You entered a negative pay rate of $" << ePR1.getbRValue() << ".\n";
                        }//catch ePR shift 1
                    } // while paytry for shift 1
                    pay = hoursWorked*hourlyRate;
                    cout << "Your pay for the week is $" << pay << ".\n";
                    shifttry = false;
                    break;
                }//case 1
                    
                case 2: {hoursWorked = Utilities::inputDouble("Please input hours worked.\n", 0, 40, -99);
                    while (paytry2 == true){
                        double tempRate2 = Utilities::inputDouble("Please input the employee's pay rate.\n",-100, 25.00 , -99);
                        try { //try for pay rate w/ shift 2
                            setHourlyRate(tempRate2);
                            pay = hoursWorked*(hourlyRate*1.25);
                            cout << "Your pay for the week is $" << pay << ".\n";
                            paytry2 = false;
                            shifttry = false;
                        }//try payrate for shift 2
                        catch (invalidPayRate ePR2){
                            cout << "You entered the invalid pay rate of $" << ePR2.getbRValue() << ".\n";
                        }//catch
                    }// while paytry for shift 2
                    break;
                }//case 2
                default: cout << "You did not enter a 1 or a 2.\n";  //why does it end with this after every time I run the program??
            }//switch
        }//try for shift
        
        catch (invalidShift eS){
            cout << eS.getbSValue() << " is an invalid value for shift.\n";
        }//catch
    }//while shift try
    return pay;
    
}


