#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int appoint, arrive;
    cin >> appoint >> arrive;

    arr[i] = appoint - arrive;
  }

  if (n % 2 == 1) {//홀수
    cout << 1 << endl;
    return 0;
  }

  sort(arr.begin(), arr.end());
  cout << abs(arr[n / 2] - arr[n / 2 - 1])  + 1 << endl;
}