/*
Height of the tree is the highest level from Root Node to any leaf. We can implement it by the help of recursion. We will mark root as a node and check the height of left subtree and right subtree in recursive calls.
Our base condition will be our leaf as it will have height zero. So we will return 0 and similarly the stack calls will be excuted.
Finally we shall return the maximum of left or Right subtrees height and  add 1 for the root Node.
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

int findHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight,rightHeight) + 1;
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
    int height = findHeight(root);
    std::cout<<"The Height of this Binary Tree Is : "<<height<<endl;
}
/*
Time Complexity : O(N) As we are checking the recussive calls for both left and right part at every Nodes.
Sample Input : 
    5
    9 5 12 2 15
Sample Output : 
    The Height of this Binary Tree Is : 3
*/
