//
//  DoublyLinked.h
//  Ch 15 Asst
//
//  Created by Marcela Vazquez on 4/7/15.
//  Copyright (c) 2015 Marcela. All rights reserved.


#ifndef __Ch_15_Asst__DoublyLinked__
#define __Ch_15_Asst__DoublyLinked__

#include <stdio.h>
#include "ProductionWorker.h"


class DoublyLinked{
private:
    
    //linkNode is a struct that holds the value (pWObject) a pointer to next and a pointer to previous
    //so whenever you create a linkNode, it already has these things
    struct LinkNode{
        ProductionWorker pWObject;
        LinkNode* next;
        LinkNode* prev;
    };
    //you're creating? a LinkNode POINTER called head, current and tail that point to these things
    LinkNode* head;    //head should permanently point to the first one in the list, unless you delete everything
    LinkNode* tail;
    LinkNode* current;
    LinkNode* top;
    int size;
    int maxSize;
    
    //nodePtr is a temporary pointer (it is a pointer like head, but head is permanent and nodePtr isn't)
    //each nodePtr you make is specific to each function, which is why you can use the same name in each function
    //you need nodePtr as temporary while you move things around
    
public:
    DoublyLinked();
    DoublyLinked(int);
    ~DoublyLinked();
    
    void appendNode(ProductionWorker);
    void insertNode(ProductionWorker);
    void deleteNode(int);
    void setCurrent(int);
    void moveBack();
    void moveForward();
    void displayList() const;  //const means function will not change any data stored in the calling object
    void printCurrent();
    void pushEmployee(ProductionWorker);
    void popEmployee(ProductionWorker);
    void enqueueEmployee(ProductionWorker);
    void dequeueEmployee(ProductionWorker);
    int recursivePrint(LinkNode *);
    int callRecPrint();
    int recursiveDelete(LinkNode *);
    int callRecDelete();
    bool isEmpty();
    bool checkEmpNum(int);
    int getSize();
    
};

#endif /* defined(__Ch_15_Asst__DoublyLinked__) */

