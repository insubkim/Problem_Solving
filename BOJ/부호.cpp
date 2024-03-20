#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  for (int j = 0; j < 3; j++) {
    int N;
    cin >> N;

    long long a = 0;//9223372036854775807
    int ov = 0;
    for (int i = 0; i < N; i++) {
      long long b;
      cin >> b;
      if (a > 0 && b > 0 && b > LLONG_MAX - a) ov++; 
      if (a < 0 && b < 0 && b < LLONG_MIN - a) ov--; 
      a += b;
    }
    char rst = '?';
    if (ov > 0) rst = '+';
    else if (ov < 0) rst = '-';
    else if (a == 0) rst = '0';
    else if (a < 0) rst = '-';
    else if (a > 0) rst = '+';
    cout << rst << endl;    
  }
}