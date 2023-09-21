/**********************
Name: Sal Hernandez
Coding 05
Purpose: Define functions for stack header file
**********************/
#include "stack.h"
bool Stack::push(int id,string* ptrStack)
{
    bool pushSuccess=false;
    if(top < size && id > 0 && ptrStack && !ptrStack->empty() )
    {
        Data * create = new Data;
        create->id = id;
        create->information = *ptrStack;
        stack[++top] = create;
        pushSuccess = true;

    }
    return pushSuccess;
}
bool Stack::isEmpty()
{
    return top < 0;
}
bool Stack::pop(Data &structdata)
{
    bool popSuccess=false; // Initial flag set to false
    if(! isEmpty() )
    {
        structdata.information = stack[top]->information;
        structdata.id = stack[top]->id;
        delete stack[top--];
        popSuccess = true;
    }
    else
    {
        structdata.id = -1;
        structdata.information = "";
    }
    return popSuccess;

}
bool Stack::peek(Data &data) // Same process as pop except does not decrement top or deallocate any memory
{
    bool peekSuccess = false;
    if (isEmpty() )
    {
        data.id = -1;
        data.information ="";
    }
    else
    {
        data = *stack[top];
        peekSuccess = true;
    }
    return peekSuccess;
}
Stack::Stack(int sizeIn)
{
    if (sizeIn < 2) // If size is less than 2 it will set size to 10 otherwise--
    {
        size = DEFAULTSIZE;
    }
    else
    {
        size = sizeIn;
    }
    stack = new Data*[size]; // should be whatever the updated size is after validation
    top = -1;
}
Stack::~Stack()
{
    for(;top > -1;top--) // Uses a for loop, while top > -1 it will delete each top until top = -1
    {
        delete stack[top];
    }
    delete [] stack; // Final
}
int Stack::getSize()
{
    return size;
}
/*
 * write all your stack methods here
 */