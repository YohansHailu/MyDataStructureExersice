#include "BinaryTree.h"
#include <iostream>
#include <stack>

using namespace std;

void biTree::fill_random(node* &head,int height)
{
    if(height == 0)
        return;
    head = new node(); 
    head->value = (rand()%100+1); 
       
    // leave it sometimes randomly 
    int left_chance = rand()%100<70;
    int right_chance = rand()%100<70;
    
    if( left_chance ==0 && right_chance ==0 ) {
        fill_random(head->left,height-1);
        fill_random(head->right,height-1);

    }else if(left_chance != 0) {
        fill_random(head->left,height-1);

    }else if(right_chance != 0){
        fill_random(head->right,height-1);
    }
}
void biTree::copy_from(const node* iroot,node* &head)
{
    if(iroot == 0) head = 0; 
    else {
        head = new node(); 
        head->value = iroot->value;

        copy_from(iroot->left,head->left);
        copy_from(iroot->right,head->right);
    }

}
void biTree::inOrder(node* head )
{
    if(head != 0)
    {
        inOrder(head->left);
        cout<<(head->value)<<" ";
        inOrder(head->right);
    }

}

void biTree::preOrder(node* head)
{
    if(head != 0)
    {
        cout<<head->value<<" ";
        preOrder(head->left);
        preOrder(head->right);
    }
}

void biTree::postOrder(node* head)
{
    if(head != 0)
    {
        postOrder(head->left);
        postOrder(head->right);
        cout<<head->value<<" ";
    }

}

void biTree::inOrder_nrec()
{
    stack<node*> ptrStack;

    node* currentNode = root;
    while(currentNode != 0 || !ptrStack.empty())
    {
        if(currentNode != 0) 
        {
            ptrStack.push(currentNode); 
            currentNode = currentNode->left;
        }
        else{
            currentNode = ptrStack.top();
            ptrStack.pop();
            cout<<currentNode->value<<" ";
            currentNode = currentNode->right; 
        }
    
    }

    cout<<endl;
}


void biTree::preOrder_nrec()
{
    stack<node*> ptrStack;

    node* currentNode = root;
    while(currentNode != 0 || !ptrStack.empty())
    {
        if(currentNode != 0) 
        {
            cout<<currentNode->value<<" ";
            ptrStack.push(currentNode); 
            currentNode = currentNode->left;
        }
        else{
            currentNode = ptrStack.top();
            ptrStack.pop();
            currentNode = currentNode->right; 
        }
    
    }
    cout<<endl;
}

void biTree::postOrder_nrec()
{
    stack<node*> ptrStack;

    node* currentNode = root;
    while(currentNode != 0 || !ptrStack.empty())
    {
        if(currentNode != 0) 
        {
            if(currentNode->right != 0)
                ptrStack.push(currentNode->right); 

            ptrStack.push(currentNode); 
            currentNode = currentNode->left;
        }
        else{

            currentNode = ptrStack.top(); ptrStack.pop();

            if( !ptrStack.empty() && currentNode->right == ptrStack.top())
            {
                node* nextToCurrentNode = ptrStack.top();
                ptrStack.pop();

                ptrStack.push(currentNode);
                currentNode = nextToCurrentNode;
            }else
            {
                cout<<currentNode->value<<" "; 
                currentNode = 0;
            }
        }
    
    }
    cout<<endl;
}

void biTree::postOrder_nrec2()
{
    stack<node*> ptrStack;
    stack<node*> secondStack;
    
    ptrStack.push(root);
    while(!ptrStack.empty())
    {
        node* current = ptrStack.top();
        secondStack.push(current);
        ptrStack.pop();

        if(current->left!= 0)
            ptrStack.push(current->left);
        if(current->right != 0)
            ptrStack.push(current->right);
    }

    while( !secondStack.empty() )
    {
        cout<<secondStack.top()->value<<" "; 
        secondStack.pop(); 
    }
    cout<<endl;
}
void biTree::print_tree(node* head,string indent)
{
    if(head == 0)
    {
        cout<<indent<<"//"<<endl;
        return;
    }
    cout<<indent<<head->value<<endl;
    print_tree(head->right,indent+"    "); 
    print_tree(head->left,indent+"    ");
}
int biTree::get_height(node* head)
{
   if(head == 0) 
       return -1;
   else return 1+max(get_height(head->left),get_height(head->right));
}
int biTree::noOfNodes(node *head)
{
    if(head == 0) 
        return 0;
    else
        return 1 + noOfNodes(head->left) + noOfNodes(head->right);

}
int biTree::noOfLeaves(node* head)
{
    if(head == 0)
        return 0;

    if(head->left == 0 && head->right == 0)      
        return 1;

    return noOfLeaves(head->left) + noOfLeaves(head->right);
}
void biTree::destroy(node* n)
{
    if(n == 0)
        return;
    node* temp = n;    
    node* left = n->left;
    node* right = n->right;
    delete temp;

    destroy(left);
    destroy(right);
   
}
biTree::~biTree()
{
    destroy(root);
}

