/**********************
Name: Sal Hernandez
Coding 04
Purpose: Create an int stack 
*********************/
#include "main.h"
int main( int argc, char** argv)
{
    int stackTestIterations = STACKSIZE * 10;
    std::cout << "Hello, World!" << std::endl;
    Stack stack1; // Stack
    //Variables used for testing
    bool pushFlag;
    int numberPopped;
    int number = 1;
    int stackSizeTracker = 0;// Used since only allowed to have 4 public methods
    //otherwise would use getter to return stackTop

    // Loop to test push
    for (int pushTest = 0; pushTest < stackTestIterations; pushTest++) {
        number += 4;
        pushFlag = stack1.push(number);
        if (pushFlag) {
            ++stackSizeTracker;
            std::cout << "Push was successfull added : " << number << " to the stack " << "There are "
                      << stackSizeTracker << " numbers in the stack" << std::endl;
        } else {
            std::cout << "Overflow error" << std::endl;
        }
    }
    for (int popTest = 0; popTest < stackTestIterations; popTest++) {

        try //Pop should throw error since it returns number popped
        {
            numberPopped = stack1.pop();
        }
        catch (int popError) {
            std::cout << "Underflow error: Stack is empty" << std::endl;
        }
        if (!stack1.isEmpty() || stackSizeTracker == 1) {
            stackSizeTracker--;
            std::cout << numberPopped << " was popped from the stack, there are " << stackSizeTracker
                      << " numbers left in the stack." << std::endl;
        }


    }

    char letter = 'a';
    stackSizeTracker = 0;
    for (int pushTest = 0; pushTest <= stackTestIterations; pushTest++) {
        pushFlag = stack1.push(letter);

        if (pushFlag) {
            ++stackSizeTracker;
            std::cout << "Push was successfull added : " << letter << " to the stack " << "There are "
                      << stackSizeTracker << " numbers in the stack" << std::endl;
        } else {
            std::cout << "Overflow error" << std::endl;
        }
        letter++;
    }
    for (int popTest = 0; popTest <= STACKSIZE * 1.1; popTest++) {

        try //Pop should throw error since it returns number popped
        {
            numberPopped = stack1.pop();
        }
        catch (int popError) {
            std::cout << "Underflow error: Stack is empty" << std::endl;
        }
        if (!stack1.isEmpty() || stackSizeTracker == 1) {
            stackSizeTracker--;
            std::cout << numberPopped << " was popped from the stack, there are " << stackSizeTracker
                      << " numbers left in the stack." << std::endl;
        }
    }
    //Random function tester
    number = 1;
    stackSizeTracker = 0;
    for(int randomFunctions = 0;randomFunctions < stackTestIterations; randomFunctions++)
    {
        int randomPick = rand() % 4;
        if (randomPick == 0) {

            bool pushCall = stack1.push(number);
            if (pushCall) {
                std::cout << number << " was added to the stack" << std::endl;
                number++;
                ++stackSizeTracker;
            }
            if (!pushCall) {
                std::cout << "push(): Overflow error, stack is full" << std::endl;
            }
        } else if (randomPick == 1) {
            try {
                std::cout << stack1.peek() << " is the number at the top of the stack" << std::endl;
            }
            catch (char peekErrorUnderflow) {
                std::cout << "peek():No numbers in stack: Underflow Error" << std::endl;
            }
        } else if (randomPick == 2) {
            if (!stack1.isEmpty() || stackSizeTracker == 1) {
                --stackSizeTracker;
            }
            try {
                std::cout << stack1.pop() << " was removed from the stack, there are " << stackSizeTracker
                          << " numbers in the stack." << std::endl;
            }
            catch (int popError) {
                std::cout << "pop(): No numbers in stack: Underflow Error" << std::endl;
            }
        } else {
            if (stack1.isEmpty()) {
                std::cout << "empty(): no numbers in stack." << std::endl;
            }
            else
            {
                std::cout << "empty(): Stack has numbers. stack is not empty" << std::endl;
            }
        }
    }
    return 0;
}