/*
With the help of Stack we can reverse a String. The Procedure Follows as We will initially iterate over whole string and push the  Letters on Stack.
We know Stack is LIFO (Last In First Out) type of Abstract Data Structure. So, Last we stacked the Last Alphabet of the String. 
So, We will now overwrite the String in Reverse order with top alphabet and pop it to go to next alphabet.
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

void Reverse(string &input,int n){
    stack<char> S;
    for(int i=0; i<n; i++){
        S.push(input[i]);
    }
    for(int i=0; i<n; i++){
        input[i] = S.top();
        S.pop();
    }
}
int main(){
    string input;
    std::cout<<"Enter your String : ";
    getline(cin,input);
    std::cout<<"Your Reversed String is : ";
    Reverse(input,input.length());
    std::cout<<input;
}
/*
    Time Complexity : O(N) We iterate the whole string whose length is n.
    Space Complexity : O(N) We store all the Aplhabet on the Stack 
    
Sample Input :
    PROGRAMMING
Output :
    Your Reversed String is : GNIMMARGORP
*/
