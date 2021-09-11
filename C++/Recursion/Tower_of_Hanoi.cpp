/*
Tower of Hanoi is the standard puzzle where you need to shift all the stacked plates from one rod to another rod with the help of one extra supportive rod.
The Approach to solving this problem would be firstly a base case wherein you would just transfer the plate from your required rod to the final rod. But incase you have more rods then algorithm you need to follow is simple. Once just add from initial rod to extra rod and then move from extra rod to final rod and after that if any plate still remains in extra rod then move it back to main rod.
*/
#include<bits/stdc++.h>
using namespace std;

void tower_of_Hanoi(int n,char from, char to, char extra){
    if(n==1){
        std::cout<<"Move from "<<from<<" to "<<to<<"\n";
        return;
    }
    tower_of_Hanoi(n-1,from,extra,to);
    std::cout<<"Move from "<<from<<" to "<<to<<"\n";
    tower_of_Hanoi(n-1,extra,to,from);
}

int main(){
    int n;
    std::cin>>n;
    tower_of_Hanoi(n,'A','B','C');
}
/*
Time Complexity : O(2^n) // Total Steps : 2^n - 1
Sample Input :
    3
Sample Output : 
    Move from A to B
    Move from A to C
    Move from B to C
    Move from A to B
    Move from C to A
    Move from C to B
    Move from A to B
*/
