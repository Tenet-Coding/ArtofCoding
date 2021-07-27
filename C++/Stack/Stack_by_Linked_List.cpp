/*
Using Linked List We must use the analogy with Array. In Array we have implemented the Push Pop Top isEmpty functions in constant time. 
Now for Linked List, To do these operations in constant time we should consider operations on the Head of the List. That means Push function
acts as if we are adding elements always on the Head of the List. Also Pop it from head. 
Push puts the data or value onto the Stack always on its top.
    Time Complexity : O(1) We can always add a value in constant time. Always on Top.
    Space Complexity : O(N) To store the N elements on the Stack present at any moment.
Pop function removes the element on the Top of the Stack.
    Time Complexity : O(1) 
    Space Complexity: O(N)
Top function returns the topmost element present on the stack.
    Time Complexity : O(1) 
    Space Complexity: O(N)
isEmpty function returns a boolean depending if the stack is empty or not.
    Time Complexity : O(1) 
    Space Complexity: O(N)

Sample Input :
    5
    4 5 7 8 3
Output :
    Your Stack is Currently :
    4 5 7 8 3 
    After Poping it changes to :
    4 5 7 8 
    The Topmost element on Stack is :
    8
    False
    False
*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* top = NULL;

void Push(int x){
  Node* temp = new Node();
  temp->data = x;
  temp->next = top;
  top = temp;
}

void Pop(){
    Node* temp = new Node();
    if(top==NULL){
        std::cout<<"List Stack is Empty"<<endl;
        return;
    }
    temp = top;
    top = top->next;
    delete temp;
}

void Top(){
    if(top==NULL){
        cout<<"List is Empty"<<endl;
    }
    std::cout<< top->data<<endl;
}

void isEmpty(){
    if(top==NULL){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}

void Print(){
    Node* n = new Node();
    n = top;
    while(n != NULL){
        std::cout<<n->data<<" ";
        n = n->next;
    }
    std::cout<<endl;
}

int main(){
   int n;
   std::cout<<"How many elements you want to push on Stack ? ";
   std::cin>>n;
   for(int i=0; i<n; i++){
       int input;
       std::cin>>input;
       Push(input);
   }
   std::cout<<"Your Stack is Currently :"<<endl;
   Print();
   Pop();
   std::cout<<"After Poping it changes to :"<<endl;
   Print();
   std::cout<<"The Topmost element on Stack is :"<<endl;
   Top();
   isEmpty();
   Pop();
   Pop();
   isEmpty();
}
