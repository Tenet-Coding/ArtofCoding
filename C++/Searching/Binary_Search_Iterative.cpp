/*
In the Binary Search for a sorted array we half the array size at each step and
compare the key with middle element. And chose the next half containing the key.
*/
#include <algorithm>
#include <iostream>
using namespace std;

int binary_search_itr(int a[], int n, int k) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == k) {
      return mid + 1;
    }
    if (a[mid] < k) {
      l = mid + 1;
    } else {
      r = mid - 1;
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
  int result = binary_search_itr(a, n, k);
  if (result == -1) {
    std::cout << "Not Found\n";
  } else {
    std::cout << "Found at position " << result << "\n";
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
