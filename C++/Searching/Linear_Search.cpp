/*
In the Linear Search we Iterate over every element of the array and return the
position if the element is found.
*/
#include <algorithm>
#include <iostream>
using namespace std;

int linear_search(int a[], int n, int k) {
  for (int i = 0; i < n; i++) {
    if (a[i] == k) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int result = linear_search(a, n, k);
  if (result == -1) {
    std::cout << "Not Found\n";
  } else {
    std::cout << "Found at position " << result << "\n";
  }
}
/*
Time Complexity : O(N)
Space Complexity : O(N)
Sample Input :
5 4
1 3 2 5 4
Sample Output :
Found at position 5
*/
