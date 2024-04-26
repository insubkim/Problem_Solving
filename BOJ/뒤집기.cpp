#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

using namespace std;

int main() {
  string b; 
  cin >> b;

  int one  = 0;
  int zero = 0;

  char prev = 0x00;
  for (auto x : b) {
    if (x == '0' && (prev == '1' || prev == 0x00))       one++;
    else if (x == '1' && (prev == '0' || prev == 0x00))  zero++;
    prev = x;
  }
  cout << min(one, zero) << endl;
}