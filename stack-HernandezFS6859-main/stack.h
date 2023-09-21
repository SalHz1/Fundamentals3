/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#ifndef STACK_H
#define STACK_H
#define DEFAULTSIZE 10

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"

class Stack {

public:

    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    bool push(int,string*); // Received an int, and passes a string via pointer notation
    bool isEmpty(); // Function checks wether a stack is empty or not
    bool pop(Data &);
    bool peek(Data &);
    Stack(int); // Default Constructor
    ~Stack(); // Default Destructor
    int getSize();
    
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need.
    // do not modify them or add any other attributes
    int top;
    int size;
    Data **stack;
    // notice stack is a pointer to a pointer. That means if you do
    // a single array allocation, you will get an array of pointers
};

#endif //STACK_H
