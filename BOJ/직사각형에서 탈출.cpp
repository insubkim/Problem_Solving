#include <iostream>
#include <vector>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int main() {
  int x, y;
  int r_x, r_y;

  cin >> x >> y >> r_x >> r_y;
  int m = x;
  if (y < m) m = y;
  if (r_x - x < m) m = r_x - x;
  if (r_y - y < m) m = r_y - y;
  cout << m << endl;
  return (0);
}
