/*
The Approach is to compare the key from last element of tbhe array and if the element is found return the element index and if you complete the array and fo not found the element return -1
*/
#include<iostream>
using namespace std;

int linear_search(int a[], int n, int key){
    int idx;
    n--;
    if(n>=0){
        if(a[n]==key){
            return n;
        }else{
            idx = linear_search(a,n,key);
        }
    }else{
        return -1;
    }
    return idx;
}

int main(){
    int n;
    std::cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        std::cin>>a[i];
    }
    int key;
    std::cout<<"Enter the element to be found : ";
    std::cin>>key;

    int index = linear_search(a,n,key);
    if(index==-1){
        std::cout<<"Element is not Found !\n";
    }else{
        std::cout<<"Element found at position "<<index+1<<"\n";
    }
}
/*
Time Complexity : O(N)

Sample Input :
    8
    1 2 3 4 5 6 9 8 7 
    4
Sample Output :
    Element found at position 4
*/
