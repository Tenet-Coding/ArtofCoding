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