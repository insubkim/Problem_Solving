#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

int main() {
  int N;
  cin >> N;


  int sum[6] = {0, };
  int up[6] = {1, 2, 3, 4, 5, 6};

  //up-a left-b front-c right-d back-e down-f
  int a, b, c, d, e, f;
  while (N--) {
    cin >> a >> b >> c >> d >> e >> f;

    for (int i = 0; i < 6; i++) {
      if (up[i] == a) { sum[i] += max(max(b, c), max(d, e)); up[i] = f; }
      else if (up[i] == b) { sum[i] += max(max(a, c), max(e, f)); up[i] = d; }
      else if (up[i] == c) { sum[i] += max(max(a, b), max(d, f)); up[i] = e; }
      else if (up[i] == d) { sum[i] += max(max(a, c), max(e, f)); up[i] = b; }
      else if (up[i] == e) { sum[i] += max(max(a, b), max(d, f)); up[i] = c; }
      else if (up[i] == f) { sum[i] += max(max(b, c), max(d, e)); up[i] = a; }
    }
  }

  int max_sum = 0;
  for (int i = 0; i < 6; i++) {
    max_sum = max(max_sum, sum[i]);  
  }
  cout << max_sum << endl;
}