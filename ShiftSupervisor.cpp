//
//  ShiftSupervisor.cpp
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 3/18/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#include "ShiftSupervisor.h"
#include <iostream>
#include "utilities.h"
using namespace std;

//Constructor Methods

ShiftSupervisor::ShiftSupervisor(void){
    yearlySalary = 25,000;
    EOYbonus = 0;
}

//Destructor Method
ShiftSupervisor::~ShiftSupervisor(void){}


//Mutator/Set Methods
bool ShiftSupervisor::setYearlySalary(){
    yearlySalary = Utilities::inputDouble("Please enter the employee's yearly salary.\n", 25000, 300000, -99);
    return true;
}
bool ShiftSupervisor::setEOYbonus(){
    EOYbonus = Utilities::inputDouble("Please input the employee's end of year bonus.\n", 0, 5000 , -99);
    return true;
}

//Accessor/ Get Methods
double ShiftSupervisor::getYearlySalary(void) const{
    return yearlySalary;
}
double ShiftSupervisor::getEOYbonus(void) const{
    return EOYbonus;
}

//virtual pay function
double ShiftSupervisor::payEmployee(){
    double pay;
    char metProduction;
    cout << "Please input if production goals were met for the week.\n Type Y for yes or N for no.\n";
    while (true) {
        cin >> metProduction;
        metProduction = toupper(metProduction);
        cout << "After toupper: " << metProduction << endl;
        if (metProduction != 'Y' && metProduction != 'N'){
            cout << "Your entry is not valid. Please enter Y for yes or N for no.\n";
            Utilities::clearCIN();
        }//if
        else {
            break;
        }
    }//while
    switch (metProduction){
        case 'Y': {yearlySalary = Utilities::inputDouble("Please input your salary.\n", 25000, 300000, -99);
            pay = (yearlySalary/52);
            cout << "Your pay for the week is $" << pay << ".\n";
            EOYbonus = yearlySalary*.1;
            cout << "You are on track to receive your End of Year Bonus of: $" << EOYbonus << ".\n";
            break;
            
        case 'N': {yearlySalary = Utilities::inputDouble("Please input your salary.\n", 25000, 300000, -99);
            pay = (yearlySalary/52);
            cout << "Your pay for the week is $" << pay << ".\n";
            break;
        }
        }
    }
    //will pay the employee the salary input by the user, and their potential EOYbonus
    //user inputs salary and y or n (or Y or N) for EOY bonus (EOYbonus will be 10% of their salary)
    //employee is paid their salary + bonus where bonus = salary*some percentage of salary or salary + bonus where bonus = 0
    return pay;
    
};






