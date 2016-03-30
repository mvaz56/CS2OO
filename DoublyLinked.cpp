//
//  DoublyLinked.cpp
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 4/7/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//


#include "DoublyLinked.h"
#include <iostream>
using namespace std;

DoublyLinked::DoublyLinked(){
    head = nullptr;
    tail = nullptr;
    current = nullptr;
};

DoublyLinked::DoublyLinked(int passedSize){
    head = nullptr;
    tail = nullptr;
    current = nullptr;
    size = 0;
    maxSize = passedSize;
};

DoublyLinked::~DoublyLinked(){
    LinkNode* nodePtr;      //to traverse the list
    LinkNode* nextNode;       //to point to the next node
    
    nodePtr = head;     //to point to the first node
    
    while (nodePtr != nullptr){     //while nodePtr is not at the end of the list
        nextNode = nodePtr->next;   //set the next node equal to nextNode
        delete nodePtr;     //delete the first (current) node
        nodePtr = nextNode;     //position nodePtr to the next node
        
    }//while
};

void DoublyLinked::appendNode(ProductionWorker pW){
    
    LinkNode* nodePtr = head;
    LinkNode* newNode = new LinkNode;  // To point to a new node
    
    // Allocate a new node and store num there.
    newNode->pWObject = pW;
    newNode->next = nullptr;
    //newNode->prev =
    
    if (!head){               // If no nodes in the list make newNode the first node
        head = newNode;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;
    }//if
    else{  // Otherwise, insert newNode at end.
        nodePtr = head;        // Initialize nodePtr to head of list.
        // Find the last node in the list.
        while (nodePtr->next)  //basically, while next is not null
            nodePtr = nodePtr->next;
        
        // Insert newNode as the last node.
        nodePtr->next = newNode;
        newNode -> prev = nodePtr;
        newNode -> next = nullptr;
        
    }//else
    
    current = newNode;
    tail = newNode;
    size++;
    
}//void function

void DoublyLinked::insertNode(ProductionWorker pW){  //need to ask where they want to insert
    LinkNode* nodePtr = head;
    LinkNode* newNode = new LinkNode;  // To point to a new node
    
    newNode->pWObject = pW;           //continuation of above line
    
    if (!head){         //if no node exists in the list, make newNode the first node
        head = newNode;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;
        current =newNode;
        return;
    }//if
    
    //BUGGGGG if the line below is put under LinkNode* newNode = new LinkNode and the list is empty
    //then inserting a new node will cause an error bc current prev is nothing
    //BUT putting it below causes it not to be inserted into the list, as shown when L is chosen from
    //the menu, BUT it will be listed as current when P is chosen. WHAT GIVES?!
    
    //LinkNode* prevNode;
    //prevNode = current -> prev;
    
    else if (current == head){
        newNode -> prev = nullptr;
        newNode -> next = current;
        current -> prev = newNode;
        current = newNode;
        head = current;
    }//if current node is first in the list
    else if (current -> prev){
        newNode -> next = current;
        newNode -> prev = current -> prev;
        current -> prev -> next = newNode;
        current -> prev = newNode;
        current = newNode;
    }//if inserting somewhere in the middle or at the end
    size++;
    
}//void

void DoublyLinked::deleteNode(int empNum){
    LinkNode *nodePtr;      //to traverse the list
    // LinkNode *previousNode;         //to point to the previous ndoe
    
    if(!head){       //if the list is empty, do nothing (aka return)
        cout << "The list is empty.\n";
        return;
    }//if
    
    nodePtr = head;
    while (nodePtr && nodePtr -> pWObject.getEmployeeNumber() != empNum){
        nodePtr = nodePtr -> next;
    }//while
    if (nodePtr == nullptr){
        cout << "That employee number is not in the list.\n";
        return;
    }//if empNum is not in list
    
    if (nodePtr -> next == nullptr && nodePtr -> prev == nullptr){
        delete nodePtr;
        current = nullptr;
        head = nullptr;
    }//if first and only
    
    else if (nodePtr -> prev == nullptr){
        nodePtr -> next -> prev = nullptr;
        head = nodePtr -> next;
        delete nodePtr;
        current = nodePtr -> next;
    }//if first
    else if (nodePtr -> next != nullptr && nodePtr -> prev != nullptr){
        nodePtr -> prev -> next = nodePtr -> next;
        nodePtr -> next -> prev = nodePtr -> prev;
        delete nodePtr;
        current = nodePtr -> next;
    }//if middle
    else if (nodePtr -> next == nullptr){
        nodePtr -> prev -> next = nullptr;
        current = nodePtr -> prev;
        delete nodePtr;
    }//if last
    else
        return;
    
    size--;
}//deleteNode

void DoublyLinked::setCurrent(int empToSet){
    LinkNode *nodePtr;
    
    if(!head){       //if the list is empty return
        cout << "The list is empty.\n";
        return;
    }//if
    
    nodePtr = head;  //positions nodePtr at the beginning of the list
    while (nodePtr && nodePtr -> pWObject.getEmployeeNumber() != empToSet){  //traverses the list searching for empToSet
        nodePtr = nodePtr -> next;
    }//while
    
    
    if (nodePtr == nullptr){
        cout << "That employee number is not in the list.\n";
        return;
    }//if empNum is not in list
    else
        current = nodePtr;
    
    if (nodePtr -> next == nullptr)
        tail = nodePtr;
    
    cout << "This is now your current employee.\n\n";
    cout << nodePtr -> pWObject.getEmployeeName() << endl;
    cout << nodePtr -> pWObject.getEmployeeNumber() << endl << endl;
};

void DoublyLinked::moveBack(){
    LinkNode *nodePtr;
    nodePtr = current;
    
    if(!head){       //if the list is empty, do nothing (aka return)
        cout << "The list is empty.\n";
        return;
    }//if
    
    if (nodePtr -> prev == nullptr){
        cout << "You are already at the beginning of the list.\n";
        return;
    }//if
    else{
        current = nodePtr -> prev;
    }
};

void DoublyLinked::moveForward(){
    LinkNode *nodePtr;
    nodePtr = current;
    
    if(!head){       //if the list is empty, do nothing (aka return)
        cout << "The list is empty.\n";
        return;
    }//if
    
    if (nodePtr -> next == nullptr){
        cout << "You are already at the end of the list.\n";
        return;
    }//if
    else{
        current = nodePtr -> next;
    }
    
    if(nodePtr -> next == nullptr)
        tail = nodePtr;
};


void DoublyLinked::displayList() const{
    LinkNode *nodePtr; //to move through the list
    nodePtr = head;  //positions nodePtr at the head of the list
    
    if (!nodePtr)
        cout << "The list is empty.\n";
    
    while (nodePtr){                        //while nodePtr points to a node, traverse the list
        cout << "Employee name: " << nodePtr -> pWObject.getEmployeeName() << endl;
        cout << "Employee number: " << nodePtr -> pWObject.getEmployeeNumber() << endl;  //display the value in this node
        nodePtr = nodePtr->next;            //moves to the next node
    }//while
};

void DoublyLinked::printCurrent(){
    LinkNode *nodePtr;
    nodePtr = current;
    
    //when I didn't have the if statement, an attempt to print the the current employee
    //resulted in an lldb error, BUT that doesn't happen when you choose to print the entire list
    
    if (!current){
        cout << "The list is empty.\n\n";
        return;
    }
    else{
        cout << "Employee name: " << nodePtr -> pWObject.getEmployeeName() << endl;
        cout << "Employee number: " << nodePtr -> pWObject.getEmployeeNumber() << endl << endl;
    }
    
};


void DoublyLinked::pushEmployee(ProductionWorker pW){     //done
    LinkNode* nodePtr = head;
    LinkNode* newNode = new LinkNode;  // To point to a new node
    
    // Allocate a new node and store num there.
    newNode->pWObject = pW;
    newNode->next = nullptr;
    //newNode->prev =
    
    if (!head){               // If no nodes in the list make newNode the first node
        head = newNode;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;
    }//if
    else{  // Otherwise, insert newNode at end.
        nodePtr = head;        // Initialize nodePtr to head of list.
        // Find the last node in the list.
        while (nodePtr->next)  //basically, while next is not null
            nodePtr = nodePtr->next;
        
        // Insert newNode as the last node.
        nodePtr->next = newNode;
        newNode -> prev = nodePtr;
        newNode -> next = nullptr;
        
    }//else
    
    current = newNode;
    tail = newNode;
    size++;
    
};

void DoublyLinked::popEmployee(ProductionWorker pW){   //done
    LinkNode* nodePtr = head;
    
    if(!head){       //if the list is empty return
        cout << "The stack is empty. You cannot pop (lock and drop it).\n";
        return;
    }
    
    else{
        nodePtr = tail;
        cout << "Employee name: " << nodePtr -> pWObject.getEmployeeName() << endl;
        cout << "Employee number: " << nodePtr -> pWObject.getEmployeeNumber() << endl << endl;
    }//else
    
    if (nodePtr -> prev == nullptr && nodePtr -> next == nullptr){ //if first and only
        delete nodePtr;
        current = nullptr;
        head = nullptr;
    }//if first and only
    
    else{
        nodePtr -> prev -> next = nullptr;
        tail = nodePtr -> prev;
        current = tail;
        delete nodePtr;
    }//else
    
    size--;
}; //pop employee


void DoublyLinked::enqueueEmployee(ProductionWorker pW){
    LinkNode* nodePtr = head;
    LinkNode* newNode = new LinkNode;  // To point to a new node
    
    // Allocate a new node and store num there.
    newNode->pWObject = pW;
    newNode->next = nullptr;
    //newNode->prev =
    
    if (!head){               // If no nodes in the list make newNode the first node
        head = newNode;
        newNode -> next = nullptr;
        newNode -> prev = nullptr;
    }//if
    else{  // Otherwise, insert newNode at end.
        nodePtr = head;        // Initialize nodePtr to head of list.
        // Find the last node in the list.
        while (nodePtr->next)  //basically, while next is not null
            nodePtr = nodePtr->next;
        
        // Insert newNode as the last node.
        nodePtr->next = newNode;
        newNode -> prev = nodePtr;
        newNode -> next = nullptr;
        
    }//else
    
    current = newNode;
    tail = newNode;
    size++;
};

void DoublyLinked::dequeueEmployee(ProductionWorker pW){
    LinkNode *nodePtr;
    
    if(!head){       //if the list is empty return
        cout << "The list is empty. You cannot pass go; you cannot collect $200.\n";
        return;
    }//if
    else{
        nodePtr = head;
        cout << "Employee name: " << nodePtr -> pWObject.getEmployeeName() << endl;
        cout << "Employee number: " << nodePtr -> pWObject.getEmployeeNumber() << endl << endl;
    }//else
    
    if (nodePtr -> next == nullptr){ //if first and only
        delete nodePtr;
        current = nullptr;
        head = nullptr;
    }//if first and only
    
    else{
        nodePtr -> next -> prev = nullptr;
        head = nodePtr -> next;
        delete nodePtr;   //bad access. fix this. if it is the only one left, do something different
        current = head;
    }//else not first and only
    
    size--;
    
}; //dequeue

int DoublyLinked::recursivePrint(LinkNode *nodePtr){
    
    if (nodePtr){
        cout << nodePtr -> pWObject.getEmployeeName() << endl;
        cout << nodePtr -> pWObject.getEmployeeNumber() << endl;
        return 1 + recursivePrint(nodePtr -> next);
    }
    else
        return 0;
}

int DoublyLinked::callRecPrint(){
    return recursivePrint(head);
}


int DoublyLinked::recursiveDelete(LinkNode *nodePtr){
    
    if (nodePtr){
        deleteNode(nodePtr -> pWObject.getEmployeeNumber());
        return 1 + recursiveDelete(nodePtr -> next);
    }
    else
        return 0;
}

int DoublyLinked::callRecDelete(){
    return recursiveDelete(head);
}

int DoublyLinked::getSize(){
    return size;
}

bool DoublyLinked::checkEmpNum(int empNumTry){
    LinkNode* nodePtr;
    nodePtr = head;
    
    while (nodePtr){
        if(nodePtr -> pWObject.getEmployeeNumber() == empNumTry)
            return true;
        else{
            nodePtr = nodePtr -> next;
        }//else
    }//while
    return false;
    
}//bool





