#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long long X, Y;

  cin >> X >> Y;
  
  int Z = (Y * 100) / X;
  
  if (Z >= 99) {
    cout << -1 << endl;
    return 0;
  }

  int result = (Y * 100 - Z * X - X) / (Z - 99);
  if ((Y * 100 - Z * X - X) % (Z - 99))
    result++;
  cout << result  << endl;

}