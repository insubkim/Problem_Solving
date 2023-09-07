#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;

void solve(int storey, int rock) {
  if (storey == 0) {
    arr.push_back(rock);
    return;
  }
  int v = storey % 10;
  // +
  if (storey > 5) solve((storey + (10 - v)) / 10, rock + (10 - v));
  // -
  solve((storey - v) / 10, rock + v);
}

int solution(int storey) {
  solve(storey, 0);
  sort(arr.begin(), arr.end());
  return arr[0];
}

#include <iostream>
int main() {
  int a = solution(9);
  cout << a << std::endl;
  return 0;
}