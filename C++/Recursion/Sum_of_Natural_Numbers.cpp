/*
For recursive approach to find the sum of Natural numbers base condition would be to return 1 when n is 1 otherwise return adding n and sum of n-1 numbers.
*/
#include<bits/stdc++.h>
using namespace std;

int naturalSum(int n){
    if(n==1){
        return 1;
    }
    return n+naturalSum(n-1);
}

int main(){
    int n;
    std::cin>>n;
    std::cout<<naturalSum(n);
}
/*
Time Complexity : O(N)
Sample Input : 
    6
Sample Output :
    21 // 1+2+3+4+5+6
*/
