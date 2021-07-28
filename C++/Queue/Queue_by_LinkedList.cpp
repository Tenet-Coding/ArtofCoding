/*
Queue is FIFO (First In First Out) Kind of Data Structure. 
It will line up all the requests and execute a particular operation on the request that was send first.
In Queues we add the element to the End or Rear part and remove it from Starting Positions.
Let us now see the Linked-List based Implementation of Queue.
*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
Node* front;
Node* rear;

bool isEmpty(){
    if(front==NULL && rear==NULL){
        return true;
    }else{
        return false;
    }
}

void enQueue(int x){
   Node* temp = new Node();
   temp->data = x;
   temp->next = NULL;
   if(front==NULL && rear==NULL){
       front = rear = temp;
       return;
   }
   rear->next = temp;
   rear = temp;
}

void deQueue(){
    Node* temp = new Node();
    if(front==NULL){
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }
    delete temp;
}

void printQueue(){
    Node* n = new Node();
    n = front;
    while(n != NULL){
        std::cout<<n->data<<" ";
        n = n->next;
    }
    std::cout<<endl;
}

int main(){
   int n;
   std::cout<<"Enter the number of elements you want in queue : ";
   std::cin>>n;
   for(int i=0; i<n; i++){
       int input;
       std::cin>>input;
       enQueue(input);
   }
   std::cout<<"How many Elements You want to deQueue : ";
   int k;
   std::cin>>k;
   for(int i=0; i<k; i++){
       deQueue();
   }
   printQueue();
   std::cout<<"Queue is Empty ?"<<endl;
   if(isEmpty()){
       std::cout<<"Yes"<<endl;
   }else{
       std::cout<<"No"<<endl;
   }
}
/*
    Time Complexity : O(1) In Enqueue or Dequeuewe always have a track of front and rear of the Queue. So we can perform operations in constant Time.
    Space Complexity : O(1) We do all operations with just one temp Node in track.
    
Sample Input :
     Enter the number of elements you want in queue : 7
     1 2 3 4 5 6 7
     How many Elements You want to deQueue : 5
Output :
     6 7 
     Queue is Empty ?
     No
*/
