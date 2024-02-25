#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
#include <cstring>

using namespace  std;

int get_diff(const char* a, const char* b) {
  int diff = 0;
  for (int i = 0;i < strlen(a); i++) {
    if (a[i] != b[i]) diff++;
  }
  return diff;
}

int main() {
  string a, b;
  cin >> a >> b;

  int diff = 50;
  for (int i = 0; i + a.size() <= b.size(); i++) {
    diff = min(diff, get_diff(&a[0], &b[i]));
  }
  cout << diff << endl;
}