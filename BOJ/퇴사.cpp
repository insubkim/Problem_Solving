#include <iostream>
#include <vector>

using namespace std;

int solve(int N, vector<int> &T, vector<int> &P) { 
    
  return 0; 
}

int main() {
  int N;
  cin >> N;
  vector<int> T(N);
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> T[i] >> P[i];
  cout << solve(N, T, P) << endl;
  return 0;
}