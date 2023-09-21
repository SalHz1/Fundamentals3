/**********************
Name: Sal Hernandez
Coding 05
Purpose: Contains function definitions for protypes in functions header
**********************/

#include "functions.h"

void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;
    
    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete buffer;
    return;
}
void rand_int(int &randomInt)
{
    randomInt = rand() % 99999999 + 999999; //Randomize number from 999999 (6 digits to 8 digits) to 99999999

}

