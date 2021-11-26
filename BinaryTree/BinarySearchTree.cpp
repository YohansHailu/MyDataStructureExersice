#include <iostream>
#include "BinarySearchTree.h" 
using namespace std;

void biSearchTree::fill_random(int height)
{
    srand(time(0));
    height = pow(2,height);
    for(int i = 0; i<height;i++)
    {
        bool inserted;
        do{
            inserted = insert_item(rand()%100);
        }
        while(!inserted);
    }
}

void biSearchTree::fill_fromArray(int a[],int size)
{
    for(int i=0;i<size;i++)
        insert_item(a[i]);
}

bool biSearchTree::insert_item(int item)
{
    node* current = root;
    node* tailCurrent= root;
    
    node* newNode = new node(); 
    newNode->value = item;
       
     
    if(root == 0)
    {
        root = new node();
        root->value = item;
        return 1;
    }

    while(current != 0)
    {
        tailCurrent = current; 
        if(current->value == item)
            return false;
        else if(item > current->value)
            current = current->right;
        else if(item < current->value)
            current = current->left;
    }

    if(item > tailCurrent->value)
          tailCurrent->right = newNode;
    else  tailCurrent->left = newNode;

    return true;
}

bool biSearchTree::search_item(int item)
{
    if(root == 0)
        return 0;
    node* currentNode = root;
    while(currentNode  != 0)
    {
        if(currentNode->value == item) 
            return 1;
        else if(currentNode-> value < item) 
            currentNode = currentNode->right;
        else if(currentNode-> value > item) 
            currentNode = currentNode->left;
    }
   return 0; 
}

node*& biSearchTree::getRef_ptr(node*& root,int item) 
{

    node* itemNode = root;
    node* preItemNode = 0;

    while(itemNode != 0) 
    {
        if(item == itemNode->value)break; // found the item 

        else if(item > itemNode ->value)
        {
            preItemNode = itemNode;
            itemNode = itemNode->right;
        }
        else if(item < itemNode->value)
        {
            preItemNode = itemNode;
            itemNode = itemNode->left;
        }
    }

    if(itemNode == root)    // doesn't have previous  
        return (root);
    else if(item > preItemNode->value)//is it to the right or left
        return (preItemNode->right);
    else if( item < preItemNode->value)
       return (preItemNode->left);

    return root; // item not found
}

bool biSearchTree::delete_item(int item)
{
    node*& itemNode = getRef_ptr(root,item);  
    
    if(itemNode == 0) return 0;

    node* temp = itemNode;
    if(itemNode->right != 0 && itemNode->left != 0) {
        temp = itemNode->left;
        node* preTemp = 0;
        while(temp->right != 0) {
            preTemp = temp;
            temp = temp->right;
        }
        itemNode->value = temp->value;
        if(preTemp != 0 )
            preTemp->right = temp->left;
        else itemNode->left = temp->left;
    }
    else if(itemNode->left == 0 && itemNode->right == 0) // leaf
        itemNode = 0;
   
    else if(itemNode->left != 0 && itemNode->right == 0)
        itemNode = itemNode->left;
  
    else if(itemNode->right != 0 && itemNode->left == 0)
        itemNode = itemNode->right;

    //delete temp;
    return 1;
}

void biSearchTree::left_rotate(int item)
{
     left_rotate(getRef_ptr(root,item));  
}

void biSearchTree::left_rotate(node*& rootNode)
{
    
    if(rootNode != 0 && rootNode->right != 0 )
    {
        node* newRoot = rootNode->right; 
        rootNode->right = newRoot->left;
        newRoot->left = rootNode;

        rootNode = newRoot;
    }
}

void biSearchTree::right_rotate(int item)
{
    right_rotate(getRef_ptr(root,item));
}
void biSearchTree::right_rotate(node*& rootNode)
{
   
    if(rootNode!= 0 && rootNode->left != 0 )
   {
        node* newRoot = rootNode->left; 
        rootNode->left = newRoot->right;
        newRoot->right = rootNode;
        rootNode = newRoot;
    }
}
//void biSearchTree::balanceLeftHight(node* &item)
//{
//}
//void biSearchTree::balanceRightHight(node* &item)
//{
//}
