/**********************
Name: Sal Hernandez
Coding 08
Purpose: Contains function prototypes for bintree.cpp
**********************/
#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H
#include "data.h"
#include <iostream>
using std::cout;
using std::endl;

class BinTree
{
public:
    BinTree();
    //Initialize root to null and count to 0
    ~BinTree();
    // Calls clearTree();
    bool isEmpty();
    // Checks if any root
    int getCount();
    //Counts total nodes
    bool getRootData(Data*);
    //Pass an empty struct, fill roots data if tree is not empty
    //otherwise -1 and ""
    void displayTree();
    // 1)Show if tree is empty or not
    // 2) Show tree height
    // 3) Get Node count
    //-------------------------------------------------
    void clear();
    //deallocate tree and set back to empty
    bool addNode(int,const string*);
    //Duplicate ids can be added(Test data is given)
    bool removeNode(int);
    bool getNode(Data*,int);
    //Use binary search to retrieve node
    bool contains(int);
    int getHeight();
    //Dynamically calcuate height of tree, do not store height,
    // calculate each time getHeight is called
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:
    //Private Attributes
    DataNode *root;
    int count;
    //Private Overloaded functions
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int,DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);
    DataNode *createNode(int,const string*);
    DataNode *minValueNode(DataNode*);
};


#endif /* BINTREE_BINTREE_H */

