#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
#include <cstring>

using namespace  std;

int solve(int num) {
  int An_1 = num % 10;
  num = num / 10;
  int An = num % 10;
  int d = An - An_1;
  while (num) {
    int An = num % 10;
    if (An - An_1 != d) return 0;
    An_1 = An;
    num /= 10;
  }

  return 1;
}

int main(void) {
  int x;
  cin >> x;

  int cnt = 0;
  for (int i = 1; i <= x; i++) {
    cnt += solve(i);
  }
  cout << cnt << endl;
}