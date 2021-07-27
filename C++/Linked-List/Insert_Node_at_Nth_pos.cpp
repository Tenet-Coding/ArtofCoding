/*
    Insert the Node at the Nth Position
The function Insert takes two arguments in it. One the data field and other the position at which the Node is to be inserted.
*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data; // For storing values
    Node* next; // For pointing to Address to next node value.
};
Node* head; //Global Head pointer that stores head address.

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
    printList(); 
}
/*
 Time Complexity : O(N) We need to iterate the whole loop of N elements to enter N elements.
 Space Complexity : O(N) We have to store N elements in our memory space (Heap) .
Sample Input : 
    5
    2 1
    3 2
    4 1
    7 1
    8 2
Sample Output :
    7 8 4 2 3
*/
