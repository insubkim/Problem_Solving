#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int d[5001];

int main() {
  int n;
  cin >> n;

  memset(d, -1, sizeof d);
  d[3] = 1;
  d[5] = 1;
  
  for (int i = 6; i < n + 1; i++) {
    int a = d[i - 3];
    if (a != -1) {
      a++;
      d[i] = a;
    }

    int b = d[i - 5];
    if (b != -1) {
      b++;
      if (d[i] == -1) {
        d[i] = b;
        continue ;
      }
      d[i] = d[i] < b ? d[i] : b;
    }
  }
  cout << d[n] << endl;
}