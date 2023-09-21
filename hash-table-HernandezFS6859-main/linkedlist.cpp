/**********************
Name: Sal Hernandez
Coding 06
Purpose: Contains function definitions for prototypes in linkedlist header file
**********************/
#include "linkedlist.h"
LinkedList::LinkedList()
{
    head = nullptr; // Sets Node head to null since list is just created there are currently no Nodes in the list.
}
LinkedList::~LinkedList()
{
    clearList();
}

int LinkedList::getCount()
{
    int count = 0;
    Node *current = head;
    while(current != NULL)// While current points at something
    {
        count++;
        current = current->next;
    }
    return count;
}

bool LinkedList::exists(int id)
{
    bool existsFlag = false;
    Node * currentNode = head;
    while(currentNode != NULL && existsFlag == false && id > 0)
    {
        if(currentNode->data.id == id) // if found we want flag to be set to true to break out of while loop
        {
            existsFlag = true;
        }
        currentNode = currentNode->next; // Point to next node in list
    }
    return existsFlag;
}
void LinkedList::printList(bool flag) // if no flag is passed it defaults to false
{
    Node *current = head;

    while(current!= NULL) // if list is not empty
    {
        if(current->next != NULL)
        {
            std::cout <<current->data.id << " -> ";
        }
        else
        {
            std::cout <<current->data.id << " ";
        }
        current = current->next;
    }
    if(head == NULL)
    {
        std::cout << "EMPTY";
    }
}
Node * LinkedList::createNode(int id, string *Data)
{
    Node * newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *Data;
    return newNode;
}
bool LinkedList::addNode(int id, string * strPTR)
{
    bool addedNode = false;
    Node * current = head;
    if(id > 0 && !strPTR->empty()){
        if(head == NULL) {// case for head, when list is empty
            head = addHead(current,id,strPTR);
            addedNode = true;
        }
        while(addedNode == false && current != NULL){
            if(head->data.id > id){ //new head case
                head = addHead(head,id,strPTR);
                addedNode = true;
            }
            if(current->data.id < id && current->next == NULL){ // New tail case
                current->next = addTail(current,id,strPTR);
                addedNode = true;
            }
            if(current->next != NULL && current->next->prev != NULL && id > current->data.id && current->next->data.id > id){// adding in between
                current->next = addInBetween(current,current->next,id,strPTR);
                addedNode = true;
            }
            current = current->next;
        }
    }
    return addedNode;
}
Node * LinkedList::addHead(Node *currentHead,int id, string *strPtr)
{
    Node *newHead;
    newHead = createNode(id,strPtr);
    if(currentHead != NULL)
    {
        newHead->next = currentHead;
        newHead->prev = NULL;
        currentHead->prev = newHead;
    }
    if(currentHead == NULL)
    {
        currentHead = newHead;
        currentHead->prev = NULL;
        currentHead->next = NULL;
    }
    return newHead;
}
Node * LinkedList::addTail(Node *currentTail, int id, string *strPtr)
{
    Node * newTail;
    newTail = createNode(id,strPtr);
    currentTail->next = newTail;
    newTail->prev = currentTail;
    newTail->next = NULL;
    return newTail;
    // tail = newTail
}
Node * LinkedList::addInBetween(Node *left, Node *right, int id, string *strPtr)
{
    Node *between;
    between  = createNode(id,strPtr);
    between->next = right;
    between->prev = left;
    left->next = between;
    right->prev = between;
    return  between;
}
bool LinkedList::getNode( int id, Data * emptyData)
{
    bool getNodeFlag = false;
    Node * currentNode;
    currentNode= head;

    while(currentNode != NULL && getNodeFlag == false)
    {
        if (id > 0 && currentNode->data.id == id)
        {
            emptyData->id = id;
            emptyData->data = currentNode->data.data;
            getNodeFlag = true;
        }
        if(currentNode->data.id != id)
        {
            emptyData->id = -1;
            emptyData->data ="";
        }
        currentNode = currentNode->next;
    }
    return getNodeFlag;
}
bool LinkedList::deleteNode(int id)
{
    Node * current = head;
    bool deletedNode = false;
    while(current != NULL && deletedNode == false)
    {
        if(current->data.id == id && current->prev == NULL && current->next != NULL) // case for when id is the head and more than 1 node
        {
            head = current->next;
            head->prev = NULL;
            delete current;
            deletedNode = true;
        }
        if(current->data.id == id && current->prev == NULL && current->next == NULL) // Case for only node is the head
        {
            head = NULL;
            delete current;
            deletedNode = true;
        }
        if(current->data.id == id && current->next == NULL && current->prev != NULL) // Tail case
        {
            current->prev->next = NULL;
            delete current; deletedNode = true;
        }
        if(current->data.id == id && current->next != NULL && current->prev != NULL)// Inbetween case
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            deletedNode = true;
        }
        current = current->next;
    }
    return deletedNode;
}
bool LinkedList::clearList()
{
    bool cleared = false;
    Node * temp;
    if(head != NULL)
    {
        while(head != NULL)
        {
            temp = head->next;
            delete head; // freeing allocated memory
            head = temp;
        }
        head = NULL;
        cleared = true;
    }
    return  cleared;
}

