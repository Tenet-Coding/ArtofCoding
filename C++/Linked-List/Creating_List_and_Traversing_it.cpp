#include<iostream>
using namespace std;

class Node{
    public:
    int data; // For storing values
    Node* next; // For pointing to Address to next node value.
};
Node* head; //Global Head pointer that stores head address.

void insert(int x){
    Node* temp = new Node();
    temp->data = x; // Also representated as *(temp).data = x;

    // temp node pointer stores NULL if list is empty initially as in main function we have head = NULL
    // And if list is not empty then it will link to next address. So, temp->next = head covers both cases.
    
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
    head = NULL; // Initially head pointer address is NULL

    std::cout<<"How many numbers would you insert ? ";
    int n;
    std::cin>>n;

    int x;
    for(int i=0; i<n; i++){
        std::cout<<"Enter the Number : ";
        std::cin>>x;
        insert(x);
        printList();
    }
}