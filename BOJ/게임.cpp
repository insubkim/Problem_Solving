#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long X, Y;

  cin >> X >> Y;
  
  int Z = ((long double)Y * 100) / X;
  
  if (Z >= 99) {
    cout << -1 << endl;
    return 0;
  }

  int cnt = 0;
  while (Z == (int)(((long double)Y * 100) / X)) {
    X++;
    Y++;
    cnt++;
  }
  
  cout << cnt << endl;
}