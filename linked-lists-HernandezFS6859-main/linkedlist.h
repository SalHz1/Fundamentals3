/**********************
Name: Sal Hernandez
Coding 06
Purpose: Header file for Linked Lists, contains prototypes
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "data.h"
#include "iostream"
class LinkedList
{
public:
    //Prototypes
    LinkedList(); // Default constructor will be called when a LinkedList object is created, Needs to point Node head -> NULL when first created(List is empty)
    ~LinkedList(); // Destructor, calls clearList() method

    // Passes an int id and non-empty string by reference. Returns T/F to indicate success of adding node
    // Nodes must be stored in ASCENDING ORDER of ID (Small -> Large)
    bool addNode( int , string * );

    // passes an id of the node to delete, Returns true if node is deleted, else false
    bool deleteNode( int );

    // Receives an id and empty struct data, if an id is found it will fill the struct data and return True, if id is not found -1 will be placed in the id
    bool getNode( int , Data * );
    void printList(bool = false);
    int getCount(); // Gets a count for the # of nodes in the list. Count must be done everytime this method is called and cannot use a class attribute for count
    bool clearList(); // Reset linked list, deletes allocated memory, sets head -> NULL
    bool exists( int ); // Checks if an id exists in the List. Returns True if it exists, False if not in List
private:
    Node * head; // One-and-only one class attribute // Pointer to the FIRST node or NULL if list is empty
    // Private Helper functions
    Node * createNode(int ,string *);
    Node * addHead(Node*,int,string *);
    Node * addTail(Node*,int,string *);
    Node* addInBetween(Node*,Node*,int,string*);
};

#endif /* LINKEDLIST_H */