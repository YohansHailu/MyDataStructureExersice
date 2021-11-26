#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCG_TREE

#include "BinaryTree.h"
class biSearchTree:public biTree
{
    public:
        void fill_random(int height); 
        void fill_fromArray(int a[],int size);
        bool insert_item(int item);
 
        bool delete_item(int item);
        bool delete_item(node* &node);

        bool search_item(int item);
        node*& getRef_ptr(node*& root,int item);

        void left_rotate(int item);
        void left_rotate(node* &item);

        void right_rotate(int item);
        void right_rotate(node*  &item);

};
#endif
