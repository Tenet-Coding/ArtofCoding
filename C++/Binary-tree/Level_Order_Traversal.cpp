/*
In this program we will travese the tree in Level Order. That means we will print the Nodes present on same level at a time. We know that Tree is not a linear data structure so, We cannot re-visit the Node if we move ahead. 
We solve this problem with the use of Queue. At every Node Position, We will put the Node Address of that node and its child in Queue. And finally pop the current node after printing it. So, Left Child Node Address will be at top.
For Sample Input consider the diagram below as we will have this order in our sample input.
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

void LevelOrderTraversal(){
    if(root==NULL){
        return;
    }
    queue <Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* current = Q.front();
        cout<< current->data <<" ";
        if(current->left != NULL){
            Q.push(current->left);
        }
        if(current->right != NULL){
            Q.push(current->right);
        }
        Q.pop();
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
    LevelOrderTraversal();   
}
/*
Time Complexity : O(N) as we need to go to every Node and print the data
Space Complexity : O(N) in Worst case we will store n/2 elements Node Address in a Queue.
Sample Input : 
    7
    9 5 12 2 3 13 15
Sample Output : 
    9 5 12 2 3 13 15
*/
