//
//  BinaryTree.h
//  Ch20Asst
//
//  Created by Marcela Vazquez on 5/22/15.
//  Copyright (c) 2015 Marcela. All rights reserved.
//

#ifndef __Ch20Asst__BinaryTree__
#define __Ch20Asst__BinaryTree__

#include <stdio.h>
#include "ProductionWorker.h"

class IntBinaryTree {
private:
        struct TreeNode {
            ProductionWorker PWInfo;
            TreeNode *left;
            TreeNode *right;
        };
    
       TreeNode *root;

       // Private member functions
       void insert(TreeNode *&, TreeNode *&);
       void destroySubTree(TreeNode *);
       void deleteNode(double, TreeNode *&);
       void makeDeletion(TreeNode *&);
       void displayInOrder(TreeNode *) const;
       void displayPreOrder(TreeNode *) const;
       void displayPostOrder(TreeNode *) const;
    
public:
    // Constructor
    IntBinaryTree()
    { root = NULL; }
    
    // Destructor
    ~IntBinaryTree()
    { destroySubTree(root); }
    
    // Binary tree operations
    void insertNode(ProductionWorker);
    bool searchNode(double);
    void remove(double);
    void displayInOrder() const
    {  displayInOrder(root); }
    void displayPreOrder() const
    {  displayPreOrder(root); }
    void displayPostOrder() const
    {  displayPostOrder(root); }
};


#endif /* defined(__Ch20Asst__BinaryTree__) */


