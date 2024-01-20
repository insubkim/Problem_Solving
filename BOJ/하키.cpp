#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int W,H,X,Y,P;

  cin >> W >> H >> X >> Y >> P;
  int r = H / 2;
  int cnt = 0;
  for (int i = 0; i < P; i++) {
    int x,y;
    cin >> x >> y;
    if (X <= x && x <= X + W && \
        Y <= y && y <= Y + H) {
            cnt++;
    } else if (sqrt(pow(X - x, 2) + pow(Y + r - y, 2)) <= r) {
      cnt++;
    } else if (sqrt(pow(X + W - x, 2) + pow(Y + r - y, 2)) <= r) {
      cnt++;
    } 
  }
  cout << cnt << endl;
}
