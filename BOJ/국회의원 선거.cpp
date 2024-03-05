#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

inline bool  cmp(const int a, const int b) {
  return a > b;
}

int main() {
  int N;
  cin >> N;

  vector<int> arr(N - 1);
  int dasom;
  cin >> dasom;
  for (int i = 0; i < N - 1; i++) {
    cin >> arr[i];
  }
  
  sort(arr.begin(), arr.end(), cmp);

  int money = 0;

  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  while (dasom <= arr[0]) {
    money++;
    dasom++;
    arr[0]--;
    for (int i = 0; i < N - 2; i++) {
      if (arr[i] < arr[i + 1]) swap(arr[i], arr[i + 1]);
      else break ;
    }
  }

  cout << money << endl;
}