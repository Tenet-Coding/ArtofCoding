/*
In this program we will travese the tree in Depth Order. It has 3 permuations possible PreOrder, Inorder and PostOrder. We can implement it by recussion.
PreOrder : <data> <left> <right>  Here we will first mark the data in node the move to left untill end and then move to right parts.
InOrder : <left> <data> <right> We will move left till end then print the Node Data and then move till right end.
PostOrder : <left> <right> <data> We will move left till end Store them then move right till end and then print the data of the node. 
InOrder of the Binary Tree will give us the node elements in a sorted order.
                             9
                        5        12
                      2   3   13    15
*/
#include<iostream>
#include<queue>
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

void PreOrder(Node* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    std::cout<<root->data<<" ";
    InOrder(root->right);
}

void PostOrder(Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    InOrder(root->right);
    std::cout<<root->data<<" ";
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

    std::cout<<"The PreOrder depth level of given tree is :"<<endl;
    PreOrder(root);
    std::cout<<endl;

    std::cout<<"The InOrder depth level of given tree is :"<<endl;
    InOrder(root);
    std::cout<<endl;

    std::cout<<"The PostOrder depth level of given tree is :"<<endl;
    PostOrder(root);
    std::cout<<endl;   
}
/*
Time Complexity : O(N) as we need to go to every Node and print the data
Space Complexity : O(h) In recursive calls we are calling subtrees for particular node. So Space required for temp Node will be equal to height of the tree in worst case.
Sample Input : 
    7
    9 5 12 2 3 13 15
Sample Output : 
    The PreOrder depth level of given tree is :
    9 5 2 3 12 13 15 
    The InOrder depth level of given tree is :
    2 3 5 9 12 13 15 
    The PostOrder depth level of given tree is :
    2 3 5 12 13 15 9
*/
