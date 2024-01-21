#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long s;
  cin >> s;

  long long k = 1;
  while (k <= s) {
    s -= k;
    k++;
  }
  cout << --k;
}