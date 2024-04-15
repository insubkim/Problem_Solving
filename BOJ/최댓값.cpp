#include <iostream>
#include <cassert>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
  int int_max = 0;
  int cnt;

  for (int i = 1; i <= 9; i++) {
    int in;
    cin >> in;
    int_max = max(int_max, in);
    if (in == int_max) cnt = i;
  }
  cout << int_max << '\n' << cnt << endl;
}