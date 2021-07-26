#include<iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node* next;
};

Node* head; 

void recursivePrint(Node* temp){
    if(temp==NULL){
        std::cout<<endl;
        return;
    }
    std::cout<< temp->data <<" ";
    recursivePrint(temp->next);
    /*

    The same code can be used to print the Reversed Linked List
    in the above two lines just change the order of Recursive call
    and Printing the data.

    >    recursivePrint(temp->next);
    >    std::cout<< temp->data <<" ";

    */
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

int main(){
    head = NULL; // Empty List
    // Insert(number,position)
    Insert(2,1); //List : 2
    Insert(3,2); //List : 2,3
    Insert(4,1); //List : 4,2,3
    Insert(5,2); //List : 4,5,2,3
    recursivePrint(head);
}