/**********************
Name: Sal Hernandez
Coding 07
Purpose: Header file for HashTable, contains prototypes
**********************/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "string"
#include <iostream>
#include "linkedlist.h"
#define HASHTABLESIZE 15
using std::string;

class HashTable
{
public:
    HashTable();
    ~HashTable();
    // Pass id and string pointer,dynamically allocated inside object
    // return T/F Success/Fail ids must be unique and > 0, strings ! empty
    bool insertEntry(int ,string*);
    // Pass id and return data string associated with id, return empty
    // tring if id does not exist
    string getData(int );
    bool removeEntry(int);
    // Return number of total entries currently in hash table
    // Count = internal
    int getCount();
    //Traverses table, showing all locations and their contents
    // Only needs to show id in chain. Chain per hash table entry
    void printTable();
private:
    int hash(int);
    int count;
    LinkedList *ptrArray[HASHTABLESIZE];
};
#endif /*HASHTABLE_H*/