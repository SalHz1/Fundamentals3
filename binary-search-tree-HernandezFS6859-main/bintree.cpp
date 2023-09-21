/**********************
Name: Sal Hernandez
Coding 08
Purpose: Contains function definitions for prototypes in bintree header file
**********************/

#include "bintree.h"
//PUBLIC FUNCTIONS
BinTree::BinTree()
{
    count = 0;
    root = nullptr;
}
BinTree::~BinTree()
{
    clear();
}

bool BinTree::isEmpty()
{
    bool empty = true;
    if(root)
    {
        empty = false;
    }
    return empty;
}

int BinTree::getCount()
{
    return count;
}

bool BinTree::getRootData(Data *empty)
{
    bool getRootFlag = false;
    if(root)
    {
        empty->id = root->data.id;
        empty->information = root->data.information;
        getRootFlag = true;
    }
    else
    {
        empty->id = -1;
        empty->information = "";
    }
    return getRootFlag;
}
void BinTree::displayTree()
{
    cout << "DISPLAY TREE" << endl;
    cout << string(50,'=') << endl;
    if(isEmpty())
    {
        cout << "Tree is empty" << endl;
    }
    else
    {
        cout << "Tree is NOT empty" << endl;
    }
    cout << "Height " << getHeight() << endl;
    cout << "Node count: " << getCount() << endl;
    cout << "\nPre-Order Traversal" << endl;
    displayPreOrder();
    cout << "\nIn-Order Traversal" << endl;
    displayInOrder();
    cout << "\nPost-Order Traversal" << endl;
    displayPostOrder();
    cout << endl;
    cout << string(50,'=') << endl;


}

void BinTree::clear()
{
    clear(root);
    count = 0;
    root = nullptr;
}
bool BinTree::addNode(int id,const string *info)
{
    bool addedNode = false;
    if(id > 0 && !info->empty())
    {
        DataNode *created = createNode(id,info);
        addedNode = addNode(created,&root);
    }
    return addedNode;
}

bool BinTree::removeNode(int id)
{
    bool publicRemovedFlag = false;
    int tempcount = count;
    if(!isEmpty() && id > 0)
    {
        root = removeNode(id,root);
    }
    if(count < tempcount)
    {
        publicRemovedFlag = true;
    }
    return publicRemovedFlag;
}

bool BinTree::getNode(Data *empty, int id)
{
    bool publicGetNodeFlag = false;
    if(id > 0)
    {
        publicGetNodeFlag = getNode(empty,id,root);
    }
    return publicGetNodeFlag;
}
bool BinTree::contains(int id)
{
    bool publicContainsFlag = false;
    if(id > 0)
    {
        publicContainsFlag = contains(id,root);
    }
    return publicContainsFlag;
}

int BinTree::getHeight()
{
    return getHeight(root);
}
void BinTree::displayPreOrder()
{
    displayPreOrder(root);
}

void BinTree::displayPostOrder()
{
    displayPostOrder(root);
}
void BinTree::displayInOrder()
{
    displayInOrder(root);
}
//START OF PRIVATE FUNCTIONS
void BinTree::displayPreOrder(DataNode* temproot)
{
    if (temproot)
    {
        cout << temproot->data.id << " " << temproot->data.information << endl;
        displayPreOrder(temproot->left);
        displayPreOrder(temproot->right);
    }
}

void BinTree::displayPostOrder(DataNode *temproot)
{
    if (temproot)
    {
        displayPostOrder(temproot->left);
        displayPostOrder(temproot->right);
        cout << temproot->data.id << " " << temproot->data.information << endl;
    }
}
void BinTree::displayInOrder(DataNode *temproot) {
    if (temproot)
    {
        displayInOrder(temproot->left);
        cout << temproot->data.id << " " << temproot->data.information << endl;
        displayInOrder(temproot->right);
    }
}

bool BinTree::getNode(Data *empty, int id, DataNode *temproot)
{
    bool privateGetNodeFlag = false;
    if (temproot && privateGetNodeFlag == false)
    {
        if(id == temproot->data.id)
        {
            empty->id = temproot->data.id;
            empty->information = temproot->data.information;
            privateGetNodeFlag = true;
        }
        if(id < temproot->data.id)
        {
            privateGetNodeFlag = contains(id,temproot->left);
        }
        if(id > temproot->data.id)
        {
            privateGetNodeFlag = contains(id,temproot->right);
        }
    }
    return privateGetNodeFlag;
}
bool BinTree::contains(int id, DataNode *temproot)
{
    bool privateContainsFlag = false;
    if (temproot && privateContainsFlag == false)
    {
        if(id == temproot->data.id)
        {
            privateContainsFlag = true;
        }
        if(id < temproot->data.id)
        {
            privateContainsFlag = contains(id,temproot->left);
        }
        if(id > temproot->data.id)
        {
            privateContainsFlag = contains(id,temproot->right);
        }
    }
    return privateContainsFlag;
}
DataNode *BinTree::createNode(int id, const string *data)
{
    DataNode * newNode = new DataNode;
    newNode->data.information = *data;
    newNode->data.id = id;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return  newNode;
}

void BinTree::clear(DataNode *temproot)
{
    if(temproot)
    {
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = temproot->right = nullptr;
        delete temproot;
    }
}
bool BinTree::addNode(DataNode *newNode, DataNode **tmproot)
{
    bool privateAddNodeFlag = false;
    if(!(*tmproot)) // test root null
    {
        *tmproot = newNode;
        count++;
        privateAddNodeFlag = true;
    }
    if(*tmproot) // if root is pointing to something
    {
        if(newNode->data.id < (*tmproot)->data.id)
        {
            privateAddNodeFlag = addNode(newNode,&(*tmproot)->left);
        }
        if(newNode->data.id > (*tmproot)->data.id)
        {
            privateAddNodeFlag = addNode(newNode,&(*tmproot)->right);
        }
    }
    return privateAddNodeFlag;
}
int BinTree::getHeight(DataNode *temproot)
{
    int counter,leftHeight,rightHeight;
    leftHeight= rightHeight = counter = 0;
    if(temproot)
    {
        if(temproot->left)
        {
            leftHeight = getHeight(temproot->left);
        }
        if(temproot->right)
        {
            rightHeight = getHeight(temproot->right);
        }
        counter = std::max(leftHeight,rightHeight) +1 ;
    }
    return counter;
}

DataNode *BinTree::minValueNode(DataNode *node)
{
    DataNode *current = node;
    while(current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

DataNode *BinTree::removeNode(int id, DataNode *rootsubtree) //not true root
{
    if(rootsubtree)
    {
        if(id < rootsubtree->data.id)
        {
            rootsubtree->left = removeNode(id,rootsubtree->left);
        }
        else if(id > rootsubtree->data.id)
        {
            rootsubtree->right = removeNode(id,rootsubtree->right);
        }
        else
        {
            DataNode * temp;
            if(rootsubtree->left == NULL)
            {
                temp = rootsubtree->right;
                delete rootsubtree;
                rootsubtree = temp;
                count--;
            }
            else if(rootsubtree->right == NULL)
            {
                temp = rootsubtree->left;
                delete rootsubtree;
                rootsubtree = temp;
                count--;
            }
            else
            {
                temp = minValueNode(rootsubtree->right);
                rootsubtree->data.id = temp->data.id;
                rootsubtree->data.information = temp->data.information;
                rootsubtree->right = removeNode(temp->data.id,rootsubtree->right);
            }
        }
    }
    return rootsubtree;
}
//END OF PRIVATE FUNCTIONS