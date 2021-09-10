/*
In the Binary Search for a sorted array we half the array size at each step and compare the key with middle element. And chose the next half containing the key.
*/
#include<iostream>
#include<algorithm>
using namespace std;

int binary_search_rec(int a[], int n, int k, int l, int r){ 
    int mid = (l+r)/2;
    if(a[mid]==k){
        return mid+1;
    }
    if(a[mid]<k){
        return binary_search_rec(a,n,k,mid+1,r);
    }else{
        return binary_search_rec(a,n,k,l,mid-1);
    }   
}

int main(){
  int n,k;
  std::cin>>n>>k;
  int a[n];
  for(int i=0; i<n; i++){
    std::cin>>a[i];
  }
  int result = binary_search_rec(a,n,k,0,n-1);
  if(result == -1){
    std::cout<<"Not Found\n";
  }else{
    std::cout<<"Found at position "<<result<<"\n";
  }
}
/*
Time Complexity : O(Log(N))
Space Complexity : O(N)
Sample Input :
5 4 
1 2 3 4 5
Sample Output :
Found at position 5
*/
