#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> price(M);
  for (int i = 0; i < M; i++) {
    cin >> price[i];
  }

  sort(price.begin(), price.end());

  int max_sum = 0;
  int max_price = 0;
  for (int i = 0; i < M; i++) {
    int sell_num = min(N, (M - i));
    int sum = price[i] * sell_num;
    if (max_sum < sum) {
      max_sum = sum;
      max_price = price[i];
    }
  }

  cout << max_price << " " << max_sum << endl;
}