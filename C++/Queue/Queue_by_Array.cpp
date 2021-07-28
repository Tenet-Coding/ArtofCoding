/*
Queue is FIFO (First In First Out) Kind of Data Structure. 
It will line up all the requests and execute a particular operation on the request that was send first.
In Queues we add the element to the End or Rear part and remove it from Starting Positions.
Let us now see the Array based Implementation of Queue.
*/
#include<iostream>
using namespace std;
#define MAX_SIZE 100
int A[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty(){
    if(front==-1 && rear==-1){
        return true;
    }else{
        return false;
    }
}

void enQueue(int x){
    if(rear==MAX_SIZE){
        std::cout<<"Queue is Full"<<endl;
        return;
    }
    if(isEmpty()){
        front = 0;
        rear = 0;
    }else{
    rear++;
    }
    A[rear] = x;
}

void deQueue(){
    front++;
}

void printQueue(){
    for(int i=front; i<=rear; i++){
        std::cout<<A[i]<<" ";
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
    Space Complexity : O(N) We need Space to store N queued elements over the entire program.
    
Sample Input :
     Enter the number of elements you want in queue : 7
     1 2 3 4 5 6 7
     How many Elements You want to deQueue : 5
Output :
     6 7 
     Queue is Empty ?
     No
*/
