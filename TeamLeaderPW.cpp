//
//  TeamLeaderPW.cpp
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 3/18/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#include "TeamLeaderPW.h"
#include <iostream>
#include "utilities.h"
#include "ProductionWorker.h"
using namespace std;

//Constructor Methods

TeamLeader::TeamLeader(void){
    requiredT_hours = 5;
    attendedT_hours = 0;
    monthlyBonus = 0;
}

//Destructor Method
TeamLeader::~TeamLeader(void){}


//Mutator/Set Methods
bool TeamLeader::setRequiredT_hours(){
    requiredT_hours = Utilities::inputDouble("Please enter the Team Leader's required training hours for the month.\n", 0, 100, -99);
    return true;
}
bool TeamLeader::setAttendedT_hours(){
    attendedT_hours = Utilities::inputDouble("Please enter the Team Leader's attended training hours for the month.\n", 0, 100, -99);
    return true;
}
//monthly bonus depends on the hours of training the employee does
//decide what this is and change the function below to incorporate that
//if the employee does not attend required hours for that month, they do not get that month's bonus
bool TeamLeader::setMonthlyBonus(){
    monthlyBonus = Utilities::inputDouble("Please input the Team Leader's monhtly bonus.\n", 0, 500 , -99);
    return true;
}

//Accessor/ Get Methods
double TeamLeader::getRequiredT_hours(void) const{
    return requiredT_hours;
}
double TeamLeader::getAttendedT_hours(void) const{
    return attendedT_hours;
}
double TeamLeader::getMonthlyBonus(void) const{
    return monthlyBonus;
}

/*
 
 //this employee receives a monthly bonus iff they have attended the minimum MONTHLY training hours
 //virtual pay function
 //need to input shift information
 double TeamLeader::payEmployee(){
 double pay;
 pay = getHourlyRate()*getHoursWorked() + monthlyBonus;
 int endOfMonth;
 
 endOfMonth = Utilities::inputInt("Is this the last week of the month? For yes enter 1. For no enter 2.", 1, 2, -99);
 if (endOfMonth == 1){
 attendedT_hours = Utilities::inputDouble("Input your completed training hours for the month.\n", 0, 10, -99);
 if (attendedT_hours >= requiredT_hours){
 //All employees get a FIXED monthly bonus of 300 iff they have attended minimum monthly training hours
 monthlyBonus = 300;
 double setRate;
 cout << "Please input your hourly rate.\n";
 cin >> setRate;
 setHourlyRate(setRate);
 setHoursWorked();
 int IDKshift;
 cout << "Please enter your shift of 1 or 2.\n";
 cin >> IDKshift;
 //why does it not follow through with the catch error statement when I do not input a 1 or a 2??
 try{
 setShift(IDKshift);
 if (getShift() == 1){
 pay = (1.25*getHourlyRate())*getHoursWorked()+monthlyBonus;
 cout << "This is your pay for the week: $" << pay << ".\n";
 }
 else if (getShift() == 2){
 pay = getHourlyRate()*getHoursWorked()+monthlyBonus;
 cout << "This is your pay for the week: $" << pay << ".\n";
 }//else if
 else{}//for syntax?
 }//try
 catch (invalidShift e){
 cout << "You entered an invalid shift of " << e.getbSValue() << endl;
 };//catch
 
 }//nested if
 else{
 double setRate;
 cout << "Please input your hourly rate.\n";
 cin >> setRate;
 setHourlyRate(setRate);
 setHoursWorked();
 int IDKshift;
 cout << "Please enter your shift of 1 or 2.\n";
 cin >> IDKshift;
 try{
 setShift(IDKshift);
 if (getShift() == 1){
 pay = (1.25*getHourlyRate())*getHoursWorked();
 cout << "This is your pay for the week: $" << pay << ".\n";
 }
 else{
 pay = getHourlyRate()*getHoursWorked();
 cout << "This is your pay for the week: $" << pay << ".\n";
 
 }//nested else
 }//try
 catch (invalidShift){
 cout << "You entered an invalid shift.\n";
 };
 }//outer else
 
 
 }// if end of month
 else{
 double setRate;
 cout << "Please input your hourly rate.\n";
 cin >> setRate;
 setHourlyRate(setRate);
 setHoursWorked();
 pay = getHoursWorked()*getHourlyRate();
 cout << "This is your pay for the week: $" << pay << ".\n";
 
 
 }// else NOT end of month
 
 
 //will pay the employee based on hours worked and which shift just like Production Workers
 //user inputs hours, then asked to input 1 or 2 for shift
 //hours are multiplied by 15 for 1 or 18 for 2 and pay is calculated
 return pay;
 
 }
 
 */

