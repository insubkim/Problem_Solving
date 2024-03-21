#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int count_ones(int val) {
  int c = 0;
  while (val) {
    if (val & 1) c++;
    val = val >> 1;
  }
  return c;
}

int main() {
  int N,K;
  cin >> N >> K;

  int c = 0;
  while (count_ones(N) > K) {
    N++;
    c++;
  }
  cout << c << endl;
}