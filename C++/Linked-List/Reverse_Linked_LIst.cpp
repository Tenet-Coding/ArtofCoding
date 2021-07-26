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
    head = NULL; // Empty List
    // Insert(number,position)
    Insert(2,1); //List : 2
    Insert(3,2); //List : 2,3
    Insert(4,1); //List : 4,2,3
    Insert(5,2); //List : 4,5,2,3
    printList();
    printReverseList(); ////List : 3,2,5,4
}