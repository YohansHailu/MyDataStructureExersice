#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include <cmath>
using namespace std;

class node
{
    public:
        int value;
        node* left=0;
        node* right=0;
};

class biTree
{
    public:
        node* root=0; //not private for the sake copy_from()
        
        void fill_tree(); // to be implemented   

        void fill_random(node* &head,int height = 10);
        void fill_random(int height = 10)
        {
            srand(time(0));
            fill_random(root,height);
        }

        void copy_from(const node* iroot,node* &head);
        void copy_from(const biTree tree)
        {
            copy_from(tree.root,root);
        }

        void inOrder(node *root);
        void inOrder()
        {
          inOrder(root); 
          cout<<endl;
        }
        
        void preOrder(node* head);
        void preOrder()
        {
            preOrder(root);
            cout<<endl;
        }
        
        void postOrder(node* head);
        void postOrder()
        {
            postOrder(root);
            cout<<endl;
        }
        
        void inOrder_nrec();
        void preOrder_nrec();
        void postOrder_nrec();
        void postOrder_nrec2();

        void print_tree(node* head,string indent);
        void print_tree()
        {
            print_tree(root,"");    
        }
        
        bool isEmpty()
        {
            return root==0; 
        }

        int get_height(node* head);
        int get_height()
        {
            return get_height(root);
        }
        int noOfNodes(node *head);
        int noOfNodes()
        {
            return noOfNodes(root);
        }
        int noOfLeaves(node* head);
        int noOfLeaves()
        {
            return noOfLeaves(root);
        }
        void destroy(node* n);

        ~biTree();

};
#endif
