/*
It is a very basic program that reverses a string recursively. The base case
would be if the length of string gets 0. Until then we will stack the string
character wise and start printing from end by passing substring except first
character as argument.
*/
#include <bits/stdc++.h>
using namespace std;

void reverse(string a) {
  if (a.length() == 0) {
    return;
  }
  reverse(a.substr(1));
  std::cout << a[0];
}

int main() {
  string a;
  std::cin >> a;
  reverse(a);
}
/*
Time Complexity : O(N)
Sample Input :
    debian
Sample Output :
    anibed
*/
