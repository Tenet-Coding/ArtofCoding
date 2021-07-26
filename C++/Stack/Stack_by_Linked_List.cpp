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
   Push(2);
   Push(4);
   Push(6);
   Print();
   Pop();
   Print();
   Top();
   isEmpty();
   Pop();
   Pop();
   isEmpty();
}