/*
Array, Linked List, Stacks and Queues are Linear data structures. You  can do operations keeping in mind that there is only one possible move in one direction.
Trees are hierarchical data structures. There might be more than on possible route at every step. Let us see some basic terminologies.
Root : The topmost node of tree is called Root of the tree.
Parent & Children : Any element can further split into number of more element. The main element on top of it is called Parent element and splitted elements are called Children elements.
Leaves : The elements that posses no further elements are called as leaves of tree.
Why we use tree in programming? 
Consider you want to manage hierarchical structure in computer system. Then using trees we can get the job done more easily and it is time effective as well.

Binary Tree Searching - In Binary tree searching we need to make sure that every element on left is lesser and right is greater at every particular parent node.
Consider the below given example.

In this program, Let us make a tree as shown below 
                   root                      9
                  /     \                  
                 l       r                5     12
               /  \     /  \    
              ll NULL  NULL rr          2         15

Here l <= root, r >=root, ll <= l, rr>=r are the constraints in order to make it a binary tree.
*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};
Node* root = NULL;
void Insert(int x){
    Node* current;
    Node* next;
    Node* newNode = new Node(x);
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root==NULL){
        root = newNode;
    }else{
        current = root;
        next = NULL;
        while(current!=NULL){
            next = current;
            if(newNode->data < current->data){
                current = current->left;
            }else{
                current = current->right;
            }
        }
        if(newNode->data < next->data){
            next->left = newNode;
        }else{
            next->right = newNode;
        }
    }
}

void PrintTree(){
    std::cout<<"Root Element : "<<root->data<<endl;
    std::cout<<"L (Left Child L-1) : "<<root->left->data<<endl;
    std::cout<<"R (Right Child L-1) : "<<root->right->data<<endl;
    std::cout<<"LL (Left Child L-2) : "<<root->left->left->data<<endl;
    std::cout<<"RR (Right Child L-2 : )"<<root->right->right->data<<endl; 
}

int main(){
    std::cout<<"Enter the Number of Nodes you want to insert : ";
    int n;
    std::cin>>n;
    for(int i=0; i<n; i++){
        int input;
        std::cin>>input;
        Insert(input);
    }
    PrintTree();
}
/*
Time Complexity : O(h) Inserting the element in the Binary Tree is proportional to the height of the tree. Which is the longest length from root of the tree to any of the leaf.
Sample Input : 
    5
    9 5 12 2 15
Sample Output : 
    Root Element : 9
    L (Left Child L-1) : 5
    R (Right Child L-1) : 12
    LL (Left Child L-2) : 2
    RR (Right Child L-2 : )15
*/
