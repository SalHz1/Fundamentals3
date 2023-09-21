/**********************
Name: Sal Hernandez
Coding 05
Purpose: Create a stack ADT
*********************/
#include "main.h"

int main(int argc, char **argv)
{
    std::cout << std::endl;
    srand(time(NULL));
    if(argc != 2)
    {
        std::cout << "No value was entered in the commandline. A single parameter must be entered in the commandline" << std::endl;
        return 1;
    }
    // Chars are valid input
    int commandLineSize = atoi(argv[1]); // Converting variable to pass to Stack() constructor
    Stack myStack(commandLineSize);

    std::cout << "Attempting to initialize a stack with size : "<< commandLineSize << std::endl;
    if(commandLineSize < 2)
    {
        std::cout << commandLineSize << " is less than 2 the size of the stack has been changed to :" << myStack.getSize() << std::endl;
    }
    std::cout << "Checking if stack is empty..." << std::endl;
    if (myStack.isEmpty()) // Is empty test, when stack is empty
        std::cout << "isEmpty();Stack is empty" << std::endl;

    else
        std::cout << "isEmpty();Stack is not empty\n";

    // testing peek and pop on an empty stack
    Data peek;
    peek.id=0;
    peek.information ="";

    if(myStack.peek(peek))  // Peek test when stack is empty
    {
        std::cout << "peek();Stack is not empty" << std::endl;

    }
    else
    {
        std::cout << "peek();Stack is empty" << std::endl;
    }
    //Testing pop on an empty stack
    if(myStack.pop(peek))
    {
        std::cout << "pop(); Pop Successful" << std::endl;
    }
    else
    {
        std::cout << "pop(); Stack is empty, pop was unsuccessful." << std::endl;
    }
    std::string strtemp;
    int randomInt;
    // Testing random Functions
    int choice = rand() % 6 + 1;
    std::cout << "\n\nNow testing random LOOP\n-------------------------------\n\n\n";
    for (int test = 0; test < ( myStack.getSize() * TESTMULTIPLIER) ; test++)
    {
       rand_string(&strtemp);
       rand_int(randomInt);


       switch(choice)
       {
           case 1:
           case 2:
               if(myStack.push(randomInt,&strtemp)  )
               {

                  std::cout << "Pushed " << randomInt << " and " << strtemp << std::endl;
               }
               else
               {
                   std::cout << "push(); Push unsuccessfull" << std::endl;
               }
               break;
           case 3:
           case 4:
               if(myStack.pop(peek))
               {
                   std::cout << "pop(); Pop was successfull" << std::endl;
               }
               else
               {
                   std::cout << "pop(); stack is empty, pop was unsuccessfull" << std::endl;
               }
                break;
           case 5:
               if(myStack.peek(peek))
               {
                  std::cout << "peek(); Peek was successfull " << std::endl;
               }
               else
               {
                   std::cout << "peek(); Peek unsuccessfull, cannot peek empty stack" << std::endl;
               }
               break;
           case 6:
               if(myStack.isEmpty() )
               {
                   std::cout << "isEmpty();Stack is empty" << std::endl;
               }
               else
               {
                   std::cout << "isEmpty();Stack is not empty" << std::endl;
               }
               break;
       }
       choice = rand() % 6 + 1;

    }
    std::cout << "\n\n\nTesting complete\n\n\n\n" << std::endl;
    return 0;
}
