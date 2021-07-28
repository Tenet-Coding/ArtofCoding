/*
With the help of Stack we can reverse a Linked List. We will create a Stack of Node pointer which will store the addresses of Node and head node. 
After pushing every node address in the Stack we will reverse the Links and Pop the previous links.
*/
#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
    int data; 
    Node* next; 
};
Node* head;

void Reverse(){
    if(head==NULL){
        return;
    }
    stack<Node*> S; // Create a Stack of Pointer Address that initially stores the Head Address
    Node* temp = head;
    while(temp != NULL){
        S.push(temp); // Keep pushing the Pointer Addresses on the Stack.
        temp = temp->next; 
    }
    temp = S.top(); // This will point at the last Address before NULL.
    head = temp; // make it as Head and reverse every link
    S.pop(); // Pop it to go to next links (in reverse)
    while(S.empty()==false){
        temp->next = S.top();
        S.pop();
        temp = temp->next ;
    }
    temp->next = NULL; // Finally set the first node's address pointer to NULL 
}

void insert(int x){
    Node* temp = new Node();
    temp->data = x; 
    temp->next = head;
    head = temp;
}

void printList(){
    Node* n = new Node();
    n = head;
    while(n != NULL){
        std::cout<<n->data<<" ";
        n = n->next;
    }
    std::cout<<endl;
}

int main(){
    head = NULL; 

    std::cout<<"How many numbers would you insert ? ";
    int n;
    std::cin>>n;

    int x;
    for(int i=0; i<n; i++){
        std::cout<<"Enter the Number : ";
        std::cin>>x;
        insert(x);
    }
    std::cout<<"Your List is : "<<endl;
    printList();
    std::cout<<"Your Reversed List is : "<<endl;
    Reverse();
    printList();
}
/*
    Time Complexity : O(N) We iterate the whole List of N nodes.
    Space Complexity : O(N) We store the address pointers for all N nodes. 
    
Sample Input :
    3
    1 7 8
Output :
    Your List is : 
    8 7 1 
    Your Reversed List is : 
    1 7 8
*/
