/*
In this program we check if input is palindrome or not. If start and end positions become adjacent or equal to each other then we return true as our base condition. Till then we keep recursively checking if first and last element are equal or not. At any point if it is unequal return false.
*/
#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s,int start, int end){
    if(start==end || end-start==1){
        return true;
    }
    if(s[start]==s[end]){
        return palindrome(s,start+1,end-1);
    }
    return false;
}

int main(){
    string s;
    std::cin>>s;
    int n = s.length();
    if(palindrome(s,0,n-1)){
        std::cout<<"Yes ! It is a palindrome !\n";
    }else{
        std::cout<<"No ! It is not a palindrome.\n";
    }
}
/*
Time Complexity : O(N/2)
Sample Input : 
    TeneT
Sample Output :
    Yes ! It is a palindrome !
*/
