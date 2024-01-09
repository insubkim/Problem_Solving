#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void  solve(vector<int> map, int& paper_num, int& x, int& y) {
  cin >> paper_num;
  while (paper_num--) {
    cin >> x >> y;
    for (int dy = 0; dy < 10; dy++)
      std::fill_n(map.begin() + (y + dy) * 100 + x, 10, 1);
  }
  cout << std::count(map.begin(), map.end(), 1) << endl;
}

int main() {
  int paper_num, x, y;
  vector<int> map(100 * 100);
  solve(map, paper_num, x, y);
}