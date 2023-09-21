/* 
 * File: main.cpp
 * Author: Sal Hernandez
 *
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    HashTable hashTable;
    // show it is empty by calling getCount and printTable
    cout << "Calling getCount() to test hashtable is empty, there are ... "  << hashTable.getCount() << " entries in the hashtable" << endl;
    // try and put ALL the test data into the table and show what happens
    cout << "Inserting all items into hashtable... " << endl;
    for(int insertLoop = 0;insertLoop < ( sizeof (ids)/sizeof (ids[0]) );insertLoop++) // length of array divided by size of each index = numbers in array
    {
        if (!hashTable.insertEntry(ids[insertLoop],&strs[insertLoop]))
        {
            cout << "Error adding: " << ids[insertLoop] << endl;
            strs[insertLoop] = ""; // set to nothing since we dont want to print duplicates later on
            ids[insertLoop] = 0; // can use as a further parameter to check if the string is empty
        }
        else
        {
            cout << "Success! Added : " << ids[insertLoop] << endl;
        }
    }
    cout << "There are ... " << hashTable.getCount() << " entries in the hashtable" << endl;
    cout << "Displaying each chain now..." << endl;
    hashTable.printTable();
    cout << "There are ... " << hashTable.getCount() << " entries in the hashtable" << endl;
    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.
    int counter = 0;
    cout << "Testing getData() without negative ids or empty strings..." << endl;
    for(int getDataRun = 0;getDataRun < testdatasize;getDataRun++)
    {
        if(ids[getDataRun] > 0 && !strs[getDataRun].empty())
        {

            cout <<"Entry#"<< ++counter << " " << ids[getDataRun] << " <-id,string -> " << hashTable.getData(ids[getDataRun]) << " " << endl;
        }
    }
    counter = 0;
    cout << "Testing getData() ALL DATA(including empty strings)..." << endl;
    for(int getDataRun = 0;getDataRun < testdatasize;getDataRun++)
    {
            cout << hashTable.getData(ids[getDataRun]) << endl;
    }
    cout << "There are ... " << hashTable.getCount() << " entries in the hashtable" << endl;
    cout << "Now removing each entry and showing Success/Failure" << endl;
    for(int hashIndex = 0;hashIndex < testdatasize;hashIndex++)
    {
        if(hashTable.removeEntry(ids[hashIndex]))
        {
            cout << "removeEntry:Success " << ids[hashIndex] << " " << endl;
        }
        else
        {
            cout << "removeEntry:fail " << ids[hashIndex] << endl;
        }
    }
    cout << "Checking hashtable entries..." << hashTable.getCount() << " entries." << endl;
    cout << "Testing printable showing empty..." << endl;
    hashTable.printTable();
    return 0;
}
