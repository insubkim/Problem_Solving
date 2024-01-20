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
    if (X <= x <= X + W &&
        Y <= y <= Y + H) {
            cnt++;
    } else if (sqrt(pow(X - x, 2) + (Y + r - y)) <= r) {
      cnt++;
    } else if (sqrt(pow(X + r - x, 2) + (Y + r - y)) <= r) {
      cnt++;
    } 
  }
  cout << cnt << endl;
}
