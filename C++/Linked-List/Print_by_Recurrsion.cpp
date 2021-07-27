/*
In this program you need to print the List by Recursion and this is done by printing the data with passing of recurrision call to next funtion.
*/
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
    std::cout<<"Printing your List by Recurrsion : "<<endl;
    recursivePrint(head);
}
/*
Time Complexity : O(N)
Space Complexity : O(N)

Sample Input :
    5
    2 1
    3 2
    4 1
    7 1
    8 2  
Output :
    Printing your List by Recurrsion : 
    7 8 4 2 3
*/