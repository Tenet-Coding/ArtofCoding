/*
Searching an Element in a Binary tree is most efficient method to do. 
Here you compare your key at every node. If key <= current node element then move to left child.and if key > current eleement then move  to right child.
It reduces the half of the Nodes at every tree level. It is as efficient as Binary Search Algorithm.
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

void Search(int x){
    Node* temp;
    temp = root;
    while(temp!=NULL){
        if(temp->data == x){
            break;
        }
        if(x < temp->data){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    if(temp==NULL){
        std::cout<<"NOT Found"<<endl;
    }else{
        std::cout<<"Found"<<endl;
    }
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

    int key;
    std::cout<<"Enter the element to be searched : ";
    std::cin>>key;
    Search(key);
}
/*
Time Complexity : O(log(N)) On every tree level we reduce the number of node by half for a perfect Binary Tree. This reduces the time complexity as Log of N base 2 where N is total number of nodes in a tree
Sample Input : 
    5
    9 5 12 2 15
    key = 12
    key = 18
Sample Output : 
    Found
    Not Found
*/
