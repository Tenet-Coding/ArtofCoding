/*
In this program we can find if the given string is the substring of another
string. We use an iterative logic with a point that finds first same character
and starts counting. If there is any interrupcy then it will restrart it again
If it completes successfully then it will return true.
*/
#include <iostream>
using namespace std;

bool subString(string a, string b) {
  int counter = 0;
  for (int i = 0; i < a.length(); i++) {
    if (counter == b.length()) {
      break;
    }
    if (b[counter] == a[i]) {
      counter++;
    } else {
      if (counter > 0) {
        i = i - counter;
      }
      counter = 0;
    }
  }
  if (counter < b.length()) {
    return false;
  } else {
    return true;
  }
}

int main() {
  string a;
  string b;
  std::cin >> a;
  std::cin >> b;
  if (subString(a, b)) {
    std::cout << "Yes, It is Substring\n";
  } else {
    std::cout << "No, It is not the Substring\n";
  }
}
/*
Time Complexity : O(N);
Space Complexity : O(1);

Sample Input :
    Tenet_Coding
    odi
Sample Output :
    Yes, It is Substring
/*
