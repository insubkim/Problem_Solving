#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool  cmp(pair<int, int>& a, pair<int, int>& b) {
  return a.second == b.second ? (a.first < b.first) : (a.second < b.second);
}

int main(void) {
  int n;
  cin >> n;
  vector<pair<int,int> > nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i].first >> nums[i].second;
  }
  sort(nums.begin(), nums.end(), cmp);
  for (int i = 0; i < n; i++) {
    // cout << nums[i].first << " " << nums[i].second << endl;
    printf("%d %d\n", nums[i].first, nums[i].second);
  }
  // for_each(nums.begin(), nums.end(), [] (pair<int, int>& num) {
  //   cout << num.first << " " << num.second << endl;
  // });
}