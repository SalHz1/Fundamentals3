/**********************
Name: Sal Hernandez
Coding 03
Purpose: Define functions for stack ADT
**********************/
#include "stack.h"
Stack::Stack()
{
    stackTop = -1;
}

bool Stack::push(int pushInStack)
{
    bool pushSuccess; // Defaults to false
    if(isEmpty() || stackTop < STACKSIZE-1) // if ( Empty == true && stackTop < StackSize )
    {
        stackADT[++stackTop] = pushInStack;
        pushSuccess = true;
    }
    return pushSuccess;

}
int Stack::peek() // Must return number peeked and underflow error
{
    char peekUnderflow;
    if(!isEmpty())
    {
        return stackADT[stackTop];
    }
    throw peekUnderflow;
}

int Stack::pop()
{
    int poppedNumber;
    int popError;
    if(isEmpty())
    {
        throw popError;
    }
    if(stackTop > -1)
    {
        poppedNumber = stackADT[stackTop--];
    }
    return poppedNumber;
}

bool Stack::isEmpty()
{
    return stackTop == -1; // if stacktop <= -1 then isEmpty is true
}