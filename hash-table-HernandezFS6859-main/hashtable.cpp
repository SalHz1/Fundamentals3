/**********************
Name: Sal Hernandez
Coding 07
Purpose: Contains function definitions for prototypes in hashtable header file
**********************/
#include "hashtable.h"

HashTable::HashTable()
{
    count = 0;
    for(int x = 0;x < HASHTABLESIZE;x++)
    {
        ptrArray[x] = new LinkedList;
    }

}
HashTable::~HashTable()
{
    for(int x = 0;x < HASHTABLESIZE; x++)
    {
        delete ptrArray[x]; // Delete each allocated
    }
}

int HashTable::getCount()
{
    return count;
}
int HashTable::hash(int id)
{
    return id % HASHTABLESIZE;
}

bool HashTable::insertEntry(int id, string * stringPtr)
{
    bool inserted = false;
    int position = hash(id);
    if(id > 0 && !stringPtr->empty() && ptrArray[position]->addNode(id,stringPtr) ) // id is positive, string not empty, addNode true
    {
       count++;
       inserted = true;
    }
    return inserted;
}

void HashTable::printTable()
{
    for(int x = 0; x<HASHTABLESIZE; x++) // Outer loop going through indexes
    {

        std::cout << "Entry " << x+1 << " ";
        ptrArray[x]->printList();
        std::cout << std::endl;

    }

}

bool HashTable::removeEntry(int id)
{
    bool removed = false;
    int position = hash(id);
    if(id > 0 && count > 0 && ptrArray[position]->deleteNode(id)  )
        // changed to if delete node true then decrement counter and set flag to true, since deletenode
    {
        count--;
        removed = true;
    }
    return removed;
}

string HashTable::getData(int id) // hashtable.getData(id)
{
    Data temporary;
    temporary.id = 0;
    int position = hash(id);
    string returnString = "";
    if (id > 0)
    {
        ptrArray[position]->getNode(id,&temporary);
        returnString = temporary.data;
    }
    return returnString;
}

// First go to the index
// Check if the thing index is pointing to is null