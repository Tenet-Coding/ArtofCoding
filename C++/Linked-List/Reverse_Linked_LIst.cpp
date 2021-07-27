/*
To Reverse the List we need to change the address links with each iterations and change the head position as the last node present in out List.
*/
#include<iostream>
using namespace std;
void printList(); //Function Declaration

class Node{
    public:
    int data; // For storing values
    Node* next; // For pointing to Address to next node value.
};

Node* head; //Global Head pointer that stores head address.

void printReverseList(){
    // We need three nodes to keep record of one current Node and 2 links, one pointing next and other pointing previous node
    Node* current; 
    Node*  prev;
    Node* next;
    
    current = head; 
    prev = NULL;
    while(current != NULL){
        next = current->next; //Records link to next Node from current Node
        current->next = prev; // Links Current Node to prev Node.
        prev = current;  // Converts current Node as Previous Node.
        current = next; // Assigns next node as current Node.
    }
    head = prev; //At the End current will be NULL and prev will be the last Node and that is Head in Reverse Order
    printList();
} 

void Insert(int data, int pos){
    Node* temp = new Node(); 
    temp->data = data;
    temp->next = NULL; 
    
    if(pos == 1){
        temp->next = head;  
        head = temp; 
        return;
    }
    Node* prev = head; 
    for(int i=0; i<pos-2; i++){
        prev = prev->next;
    }
    temp->next = prev->next; 
    prev->next = temp; 
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
    int n;
    std::cout<<"Enter the Number of Element you want to Insert : ";
    std::cin>>n;
    for(int i=0; i<n; i++){
        int data,position;
        std::cout<<"Enter the data you want to enter : ";
        std::cin>>data;
        std::cout<<"Enter the position where you want to add this Node : ";
        std::cin>>position;
        Insert(data,position);
    } 
    std::cout<<"Your List is "<<endl;
    printList();
    std::cout<<"Your List in Reversed Order is "<<endl;
    printReverseList(); 
}
/* 
    Time Complexity : O(N) because we irrate till the end of list
    Space Complexity : O(N) because we store all node addresses 
Sample Input :
     5
    2 1
    3 2
    4 1
    7 1
    8 2
Output :
    Your List is : 
    7 8 4 2 3
    Your List in Reversed Order is :
    3 2 4 8 7
*/
