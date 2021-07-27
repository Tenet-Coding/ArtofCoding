/*
Stacks are LIFO (Last In First Out) type of Data Structure. You can imagine them same as books submitted to teacher in school.
The basic operations that can be done with Stack are Push, Pop, Top and isEmpty.

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
#define MAX_STACK_SIZE 100

int top = -1;   //Global Declaration
int a[MAX_STACK_SIZE]; //Stack Data Structure by using Arrays

void Push(int x){
    if(top>MAX_STACK_SIZE){
        std::cout<<"Stack OverFlowed. Cannot add elements anymore."<<endl;
        return;
    }
    top++; 
    a[top] = x;
}

void Pop(){
    if(top==-1){
        std::cout<<"The Stack is Empty"<<endl;
        return;
    }
    top--;
}

void Top(){
    std::cout<<a[top]<<endl;
}

void isEmpty(){
    if(top==-1){
        std::cout<<"True"<<endl;
    }else{
        std::cout<<"False"<<endl;
    }
}

void Print(){
    for(int i=0; i<=top; i++){
        std::cout<<a[i]<<" ";
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
