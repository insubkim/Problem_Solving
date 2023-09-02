#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

int main() {
  int N, M, tmp;
  vi P;

  cin >> N;
  REP(i, 1, N) {
    cin >> tmp;
    P.PB(tmp);
  }
  cin >> M;

  if (P.size() == 1) {
    cout << 0 << endl;
    return 0;
  }

  int min, min_except_zero;
  min = 0;
  min_except_zero = 1;
  for (int i = 0; i < P.size(); i++) {
    if (P[min] >= P[i]) min = i;
    if (P[min_except_zero] >= P[i] && i > 1) min_except_zero = i;
  }

  vi s;
  // ABBBBBBBBB...
  if (M >= P[min_except_zero]) {
    s.push_back(min_except_zero);
    M -= P[min_except_zero];
  }
  if (s.empty()) {
    cout << 0;
    return 0;
  }
  while (M >= P[min]) {
    s.push_back(min);
    M -= P[min];
  }
  // CBBBBBB....
  for (int i = 0; i < s.size(); i++) {
    for (int j = s[i] + 1; j < P.size(); j++) {
      if (M + P[s[i]] >= P[j]) {
        M += P[s[i]];
        M -= P[j];
        s[i] = j;
      }
    }
  }
  if (s.empty()) cout << 0;
  for (auto x : s) cout << x;
  cout << endl;
  return 0;
}