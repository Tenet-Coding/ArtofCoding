/*
In this Iterative Program to find the Maximum and Minimum element of the tree it is intuitive that the minimum element will be present on the left most leaf and maximum element will be present on the rightmose leaf.
So, We need to keep iterating left sides from the root node untill we find leaf for Minimum element. And for Maximum element We have to itterate always right from root.
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

void findMin(){
    Node* temp = root;
    if(root==NULL){
        std::cout<<"Your Tree is Empty"<<endl;
    }
    while(temp->left != NULL){
        temp = temp->left;
    }
    std::cout<<"The minimum element in tree is : "<< temp->data <<endl;
}

void findMax(){
    Node* temp = root;
    if(root==NULL){
        std::cout<<"Your Tree is Empty"<<endl;
    }
    while(temp->right != NULL){
        temp = temp->right;
    }
    std::cout<<"The maximum element in tree is : "<< temp->data <<endl;
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
    findMax();
    findMin();
}
/*
Time Complexity : O(log(N)) On every tree level we reduce the number of node by half for a perfect Binary Tree. This reduces the time complexity as Log of N base 2 where N is total number of nodes in a tree
Sample Input : 
    5
    9 5 12 2 15
Sample Output : 
    The maximum element in tree is : 15
    The minimum element in tree is : 2
*/
