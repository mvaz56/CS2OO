//
//  BinaryTree.cpp
//  Ch20Asst
//
//  Created by Marcela Vazquez on 5/22/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#include "BinaryTree.h"
#include "ProductionWorker.h"




void IntBinaryTree::insertNode(ProductionWorker PW){
    TreeNode *newNode;      // Pointer to a new node.
    // Create a new node and store num in it.
         newNode = new TreeNode;
         newNode->PWInfo = PW;
         newNode->left = newNode->right = NULL;
    
         // Insert the node.
         insert(root, newNode);
}

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
    if (nodePtr == NULL)
        nodePtr = newNode; // Insert the node.
    else if (newNode -> PWInfo.getEmployeeNumber() < nodePtr -> PWInfo.getEmployeeNumber())
        insert(nodePtr->left, newNode); // Search the left branch.
    else
        insert(nodePtr->right, newNode); // Search the right branch.
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
    
    if(nodePtr){
        displayInOrder(nodePtr->left);
        cout << "Name: " << nodePtr -> PWInfo.getEmployeeName() << endl;
        cout << "Number: " << nodePtr -> PWInfo.getEmployeeNumber() << endl;
        displayInOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const{
    
    if (nodePtr){
        cout << "Name: " << nodePtr -> PWInfo.getEmployeeName() << endl;
        cout << "Number: " << nodePtr -> PWInfo.getEmployeeNumber() << endl;
        displayPreOrder(nodePtr -> left);
        displayPreOrder(nodePtr -> right);
    }
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const{
    
    if (nodePtr){
        displayPreOrder(nodePtr -> left);
        displayPreOrder(nodePtr -> right);
        cout << "Name: " << nodePtr -> PWInfo.getEmployeeName() << endl;
        cout << "Number: " << nodePtr -> PWInfo.getEmployeeNumber() << endl;

    }
}

bool IntBinaryTree::searchNode(double searchNumber){
    TreeNode *nodePtr = root;
    
    while (nodePtr){
        if (nodePtr -> PWInfo.getEmployeeNumber() == searchNumber)
            return true;
        else if (searchNumber < nodePtr -> PWInfo.getEmployeeNumber())
            nodePtr = nodePtr -> left;
        else
            nodePtr = nodePtr -> right;
    }
    
    return false;
}

void IntBinaryTree::remove(double empNum){
    
   deleteNode(empNum, root);
    
}

void IntBinaryTree::deleteNode(double empNum, TreeNode *&nodePtr){
    
    if (empNum < nodePtr -> PWInfo.getEmployeeNumber())
        deleteNode(empNum, nodePtr->left);
    else if (empNum > nodePtr -> PWInfo.getEmployeeNumber())
        deleteNode(empNum, nodePtr -> right);
    else
        makeDeletion(nodePtr);
    
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr){
    
// Define a temporary pointer to use in reattaching the left subtree.
TreeNode *tempNodePtr;

    if (nodePtr == NULL)
        cout << "Cannot delete empty node.\n";
    
    else if (nodePtr->right == NULL){
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;   // Reattach the left child.
        delete tempNodePtr;
    }
    
    else if (nodePtr->left == NULL){
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;  // Reattach the right child.
        delete tempNodePtr;
       }
    
    // If the node has two children.
    else{
        // Move one node to the right.
        tempNodePtr = nodePtr->right;
        
            // Go to the end left node.
            while (tempNodePtr->left)
                tempNodePtr = tempNodePtr->left;
        
                // Reattach the left subtree.
                tempNodePtr->left = nodePtr->left;
                tempNodePtr = nodePtr;
        
                // Reattach the right subtree.
                nodePtr = nodePtr->right;
                delete tempNodePtr;
    }//else
}

void IntBinaryTree::destroySubTree(TreeNode *nodePtr){
    
    if(nodePtr){
        if (nodePtr->left)
            destroySubTree(nodePtr -> left);
        if (nodePtr -> right)
            destroySubTree(nodePtr -> right);
        delete nodePtr;
    }
    
}













