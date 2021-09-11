/*
In this program we convert number from decimal to binary. We keep on dividing the number by 2 and note the remainder and then multiply 10 with it. 
*/
#include<bits/stdc++.h>
using namespace std;

int dec_to_bin(int n){
    if(n==1 || n==0){
        return n;
    }
    return n%2 + 10*dec_to_bin(n/2);
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<dec_to_bin(n);
}
/*
Time Complexity : O(Log(N))
Sample Input : 
    19
Sample Output :
    10011
*/
