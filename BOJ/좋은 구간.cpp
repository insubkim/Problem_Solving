#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> S;
  int L, N;

  cin >> L;

  for (int i = 0; i < L; i++) {
    int t;
    cin >> t;
    S.push_back(t);
  }
  
  sort(S.begin(), S.end());
  
  cin >> N;
  
  vector<int>::iterator mB = lower_bound(S.begin(), S.end(), N);
  if (*mB <= N) {
    cout << 0 << endl;
    return 0;
  }
  vector<int>::iterator mA = mB - 1;
  if (mB != S.begin() && *mA >= N) {
    cout << 0 << endl;
    return 0;
  }

  long long B = *mB - 1;
  long long A = mB == S.begin() ? 1 : *mA + 1;
  
  cout << (B - N) + (B - N + 1) * (N - A) << endl;
}