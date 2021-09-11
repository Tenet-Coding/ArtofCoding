/*
In the fibbonaci program, We have base conditions as return 1 if n is 1 or 0 if
n is 0 else return fib(n-1)+fib(n-2) recursively.
*/
#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
  if (n == 1 || n == 0) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  std::cin >> n;
  std::cout << fib(n);
}
/*
Time Complexity : O(N);
Sample Input :
    14
Sample Output :
    377
*/
