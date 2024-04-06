#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

int main() {
  int N,C,W;
  cin >> N >> C >> W;

  int max_l = 0;
  int tree[51] = {0, };
  for (int i = 1; i <= N; i++) {
    cin >> tree[i];
    max_l = max(max_l, tree[i]);
  }

  long long max_money = 0;
  for (int i = 1; i <= max_l; i++) {
    long long money = 0;
    for (int j = 1; j <= N; j++) {
      if ((tree[j] / i) == 0) continue;

      long long tmp = 0;
      tmp += (tree[j] / i) * i * W;
      tmp -= (tree[j] / i) * C;
      if (tree[j] % i == 0) tmp += C;
      if (tmp < 0) continue;
      money += tmp;
    }
    max_money = max(max_money, money);
  }
  cout << max_money << endl;
}