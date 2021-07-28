/*
Check whether the Brackets are Balanced or not using Stack.
Follow the Algorithm as "Last Unclosed, First Closed"
Scan the expression from left to right. If Opening Symbol is found add it to Stack. -> Push
If coressponding closing symbol is found then remove the last opening Symbol. -> Pop
At the end if List is found empty then brackets can be said balanced or else they are not balanced.
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

void check(string &exp, int n){
    stack<char> S;
    for(int i=0; i<n; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            S.push(exp[i]);
        } else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(S.empty()){
                std::cout<<"Not Balanced"<<endl;
                return;
            }else{
                S.pop();
            }
        }
    }
    if(S.empty()){
        std::cout<<"Yes!,The Expression of Brackets is Balanced"<<endl;
    }else{
        std::cout<<"No!,The Expression of Brackets is not Balanced"<<endl;
    }
}

int main(){
   string exp;
   std::cout<<"Enter Your Expresion of Brackets : ";
   getline(cin,exp);
   check(exp,exp.length());
}
/*
    Time Complexity : O(N) We iterate over all the characters
    Space Complexity : O(1) We store only the String Address and access it.
    
Sample Input :
    )([]{}
    ([{}])
Output :
    Not Balanced
    Yes!,The Expression of Brackets is Balanced
*/
