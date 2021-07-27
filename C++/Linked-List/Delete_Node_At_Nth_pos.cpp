/*
Delete a Node at a given position. 
The Delete Element function has ,
    Time Complexity : O(N) In Worst case we will be traversing till the end of the Linked List
    Space Complexity : O(1) We only need one Temp Node to be stored for pointing it to the node to be deleted.

Sample Input :
    4
    2 1
    3 2
    4 1
    5 2
    2
Output :
    4 2 3
*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data; // For storing values
    Node* next; // For pointing to Address to next node value.
};
Node* head; //Global Head pointer that stores head address.

void deleteElement(int n){
    Node* temp = new Node(); // Create a temp pointer address
    temp = head; // let it point to head node
    if(n == 1){
        head = temp->next; // now store temp's address as head
        delete temp; // with delete keyword free temp from memory
        return;
    }
    for(int i=0; i<n-2; i++){
        temp = temp->next;
    }
    // link node to be deleted from (n-1)th Node to n+1)th Node
    Node* prev = temp->next; 
    temp->next = prev->next;
    delete prev;
}

void Insert(int data, int pos){
    Node* temp = new Node(); // Create a Node that stores the element to be inserted
    temp->data = data;
    temp->next = NULL; // Intially let it point to NULL
    
    //If you want to insert element at pos 1 that is head position.
    if(pos == 1){
        temp->next = head;  // Our created Node points to head element 
        head = temp; // this creates the link of head pointer towards our new node.
        return;
    }
    Node* prev = head; // with the loop till n-2 pos find the link between (n-1)th and nth Node
    for(int i=0; i<pos-2; i++){
        prev = prev->next;
    }
    temp->next = prev->next; // Assign link of our created node to found link
    prev->next = temp; // point the address of (n-1)th node to our new node.
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
    
    int dlt_at;
    std::cout<<"Enter the position where you want deletion : ";
    std::cin>>dlt_at;
    deleteElement(dlt_at);
    printList();
}
