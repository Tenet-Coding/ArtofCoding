/*
This Program focuses on Creating a Linked List and traversing it for further operations to be done.
To Create a Linked List We first Create the Class named Node which stores Data and another Pointer Address Node that links to next Node.
If there is no next Node we declare the pointer address as NULL.
*/
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
   /* 
    Temp node pointer stores NULL if list is empty initially as in main function we have head = NULL
    And if list is not empty then it will link to next address. So, temp->next = head covers both cases.
   */ 
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
/*insert Function allows you to insert the Nodes in the linked list.
    Time Complexity : O(1) We add elements at head so we can do this in constant time operation
    Space Complexity : O(N) The space taken by List is depending on N, the number of nodes present in the list.

printList Function prints the list by traversing the Nodes.
    Time Complexity : O(N) We need to itterate the number of nodes present in order to print them all
    Space Complexity : O(N)
    
Sample Input : 
    5
    2 4 7 1 5
Output :
    5 1 7 4 2
*/
