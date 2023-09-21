/**********************
Name: Sal Hernandez
Coding 04
Purpose: Contain prototypes for Stack 
**********************/

#ifndef STACK_STACK_H
#define STACK_STACK_H
#define STACKSIZE 10000
class Stack
{
public:
    Stack();
    int peek();
    bool push(int);
    int pop(); //return number removed
    bool isEmpty();

private:
    int stackTop;
    int stackADT[STACKSIZE];
};
#endif

/* Test to handle underflow, overflow, incorrect input, multiple random operations in every combination. */


