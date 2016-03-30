//
//  main.cpp
//  BinaryTree
//
//  Created by Marcela Vazquez on 5/21/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include "Employee.h"
#include "TeamLeaderPW.h"
#include "ShiftSupervisor.h"
#include "ProductionWorker.h"
#include "utilities.h"
#include "DoublyLinked.h"
#include "BinaryTree.h"

using namespace std;
void menu1();
void menu2();
string menu1input();
string menu2input();
ProductionWorker employeeInfo();
ProductionWorker randomEmp();


/*int main(int argc, const char *argv[]) {
 
 
 for (int i = 0; i < argc; i++){
 cout << "Parameter" << i+1 << "is " << argv[i] << endl;
 }//for
 
 if (argc != 2){
 cout << "Invalid number of arguments.\n";
 return 0;
 }//if
 
 const int size = atoi(argv[1])
 
 */


int main(){
    ProductionWorker PW1;
    string menuChoice;
    int whichMenu;
    
    whichMenu = Utilities::inputInt("Please select 1 for ch 17-19 menu or 2 for ch 20 menu.\n", 1, 2, -9999);
    if (whichMenu == 1){
        
    DoublyLinked dL;
    
    bool continueMenu = true;
    
    while (continueMenu){
        menu1();
        menuChoice = menu1input();
        
        if (menuChoice == "A"){
            cout << "You have chosen to append (add) an employee to the end of the list.\n";
            PW1 = employeeInfo();
            //cout << PW1.getEmployeeNumber() << endl;
            dL.appendNode(PW1);
        }
        else if (menuChoice == "I"){
            cout << "You have chosen to insert an employee to the list.\n";
            cout << "The employee you enter will be inserted before the current employee.\n";
            PW1 = employeeInfo();
            dL.insertNode(PW1);
        }
        else if (menuChoice == "D"){
            cout << "You have chosen to delete an employee from the list.\n";
            cout << "Please enter the employee number of the employee you wish to delete.\n";
            dL.deleteNode(Utilities::inputInt("Enter employee number.\n", 0, 9999, -999));
        }
        else if (menuChoice == "S"){
            cout << "You have chosen to set the current list position.\n";
            dL.setCurrent(Utilities::inputInt("Enter the employee number you wish to set to current.\n", 0, 9999, -999));
        }
        else if (menuChoice == "B"){
            cout << "You have chosen to move backward in the list.\n";
            dL.moveBack();
        }
        else if (menuChoice == "F"){
            cout << "You have chosen to move forward in the list.\n";
            dL.moveForward();
        }
        else if (menuChoice == "P"){
            cout << "You have chosen to print the current employee.\n\n";
            dL.printCurrent();
        }
        else if (menuChoice == "L"){
            cout << "You have chosen to print the entire employee list.\n\n";
            dL.displayList();
        }
        
        //here beings stacks and qeues
        else if (menuChoice == "H"){
            cout << "You have chosen to push an employee onto the list.\n";
            PW1 = employeeInfo();
            dL.pushEmployee(PW1);
        }
        else if (menuChoice == "T"){
            cout << "You have chosen to pop this employee off of the list.\n";
            dL.popEmployee(PW1);
        }
        else if (menuChoice == "Q"){
            cout << "You have chosen to push an employee onto the end of the que.\n";
            PW1 = employeeInfo();
            dL.enqueueEmployee(PW1);
        }
        else if (menuChoice == "U"){
            cout << "You have chosen to remove this employee from the front of the que.\n";
            dL.dequeueEmployee(PW1);
        }
        else if (menuChoice == "G"){
            cout << "You have chosen to append a randomly generated employee to the list.\n";
            cout << "This is the employee that will be added.\n";
            PW1 = randomEmp();
            cout << "Employee name: " << PW1.getEmployeeName() << endl;
            cout << "Employee number: :" << PW1.getEmployeeNumber() << endl;
            dL.appendNode(PW1);
        }
        else if (menuChoice == "R"){
            cout << "You have chosen to recursively print the list.\n\n";
            //dL.callRecPrint();
            int total = dL.callRecPrint();
            cout << "Total amount printed is " << total << ".\n";
        }
        else if (menuChoice == "C"){
            cout << "You have chosen to recursively delete the list.\n\n";
            //dL.callRecPrint();
            int total = dL.callRecDelete();
            cout << "Total amount deleted is " << total << ".\n";
        }
        else if (menuChoice == "Z"){
            cout << "You have chosen to get the size of the list/stack/queue.\n\n";
            cout << "The size is " << dL.getSize() << ".\n";
        }
        
        
        
        else if (menuChoice == "W"){
            cout << "You have chosen to write to the disk.\n\n";
            //function call
        }
        else if (menuChoice == "V"){
            cout << "You have chosen to read from the disk.\n";
            //call function
        }
        
        
        
        else if (menuChoice == "E"){
            continueMenu = false;
        }
        else{
            cout << "You didn't do something right. Please enter a character from the menu above.\n";
        }//else
    }//while
    }//if menuchoice 1
    
    else if (whichMenu == 2){
        
        IntBinaryTree Tree;
        
        bool continueMenu = true;
        
        while (continueMenu){
            menu2();
            menuChoice = menu2input();
            
            if (menuChoice == "A"){
                cout << "You have chosen to append (add) an employee to the tree.\n";
                PW1 = employeeInfo();
                Tree.insertNode(PW1);

            }
            else if (menuChoice == "G"){
                cout << "You have chosen to add this randomly generated employee.\n";
                PW1 = randomEmp();
                cout << "Employee name: " << PW1.getEmployeeName() << endl;
                cout << "Employee number: :" << PW1.getEmployeeNumber() << endl;
                Tree.insertNode(PW1);
            }
                
            else if (menuChoice == "D"){
                cout << "You have chosen to display the tree in order.\n";
                Tree.displayInOrder();
            }
            else if (menuChoice == "F"){
                cout << "You have chosen to display the tree in pre order.\n";
                Tree.displayPreOrder();
            }
            else if (menuChoice == "H"){
                cout << "You have chosen to display the tree in post order.\n";
                Tree.displayPostOrder();
            }
            else if (menuChoice == "S"){
                cout << "You have chosen to search the tree.\n";
                cout << "Please enter the employee number of the employee you wish to find.\n";
                double search = Utilities::inputInt("Enter employee number.\n", 0, 9999, -999);
                Tree.searchNode(search);
                
                if (Tree.searchNode(search))
                    cout << "The employee was found in the tree.\n";
                else
                    cout << "The employee was not found in the tree.\n";
                
            }
            else if (menuChoice == "L"){
                cout << "You have chosen to delete a branch (don't break the tree).\n";
                cout << "Please enter the number of the employee you wish to delete.\n";
                double search = Utilities::inputInt("Enter employee number.\n", 0, 9999, -999);
                Tree.searchNode(search);
                
                if (Tree.searchNode(search)){
                    Tree.remove(search);
                    cout << "The employee attached to " << search << " was deleted.\n";
                }
                else
                    cout << "The employee was not found in the tree, thus it cannot be deleted.\n";
                
            }
            else if (menuChoice == "E"){
                cout << "Deuces.\n";
                continueMenu = false;
            }
            else
                cout << "Something went wrong.\n";
        }//while
    }//else if menu choice 2
    
    
    
    /*
     #ifdef __APPLE__
     #include "TargetConditionals.h"
     #if TARGET_OS_MAC
     cout << "Bye Bye from Mac.\n";
     #endif
     #elif __linux__
     cout << "Bye Bye from Linux.\n";
     #elif__MINGW32__
     cout << "Bye Bye from Windows.\n";
     #endif
     */
    
    return 0;
    }

ProductionWorker employeeInfo(){
    ProductionWorker theOne;
    DoublyLinked dL;
    
    theOne.setEmployeeName(Utilities::inputString("Enter employee name.\n", 0, 20));
    
    //checks employee number
    bool tryEmpNum = true;
    while (tryEmpNum){
        int tempEmpNum = Utilities::inputInt("Enter employee number between 0 and 4999.", 0, 4999, -999);
        //dL.checkEmpNum(tempEmpNum);
        if(dL.checkEmpNum(tempEmpNum)){
            cout << "The employee number you entered already exists in the list.\n";
        }//if
        else{
            theOne.setEmployeeNumber(tempEmpNum);
            tryEmpNum = false;
        }
    }//while
    
    theOne.setShift(Utilities::inputInt("Enter a 1 or 2 for shift.\n", 1, 2, -999));
    theOne.setHourlyRate(Utilities::inputDouble("Enter your hourly rate.\n", 10, 30, -999));
    theOne.setHoursWorked(Utilities::inputDouble("Please input hours worked (between 0 and 40).\n", 0, 40, -999));
    return theOne;
}

void menu1() {
    cout << "Please select from the following options.\n\n";
    cout << "A to append to the list.\n";
    cout << "I to insert an employee in the list.\n";
    cout << "D to delete an employee in the list.\n";
    cout << "S to set the current list position.\n";
    cout << "B to move back in the list.\n";
    cout << "F to move forward in the list.\n";
    cout << "P to print the current employee in the list.\n";
    cout << "L to print the entire employee list.\n";
    cout << "H to push onto the stack.\n";
    cout << "T to pop off the stack.\n";
    cout << "Q to push (enqueue) onto the end of que.\n";
    cout << "U to remove (dequeue) an element from the front of the que.\n";
    cout << "G to generate a random employee that will be appended to the list.\n";
    cout << "R to recursively print all the employees in the list.\n";
    cout << "C to recursively delete all the employees in the list.\n";
    cout << "Z to display current size of the list/stack/queue.\n";
    cout << "W to write to disk.\n";
    cout << "V to read from disk.\n";
    cout << "E to end the program.\n";
}
    
void menu2(){
    cout << "Please select from the following options.\n\n";
    cout << "A to add node.\n";
    cout << "G to add a random node.\n";
    cout << "D to display in order.\n";
    cout << "F to display in pre order.\n";
    cout << "H to display in post order.\n";
    cout << "S to search node.\n";
    cout << "L to delete node.\n";
    cout << "E to exit.\n";
}
    
string menu1input (){
    string MENUchoice = Utilities::inputString("Please enter your menu choice.\n", 1, 1);
    return Utilities::makeUpperCase(MENUchoice);
}

string menu2input (){
    string MENUchoice = Utilities::inputString("Please enter your menu choice.\n", 1, 1);
    return Utilities::makeUpperCase(MENUchoice);
}

ProductionWorker randomEmp(){
    ProductionWorker random;
    
    random.setEmployeeName("Random Employee");
    random.setEmployeeNumber(Utilities::getRandomInt(5000, 9999));
    random.setShift(Utilities::getRandomInt(1, 2));
    random.setHourlyRate(Utilities::getRandomDouble(10, 25, 2));
    random.setHoursWorked(Utilities::getRandomDouble(0, 40, 2));
    return random;
    
}


