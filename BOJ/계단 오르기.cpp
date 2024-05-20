#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int N;
  cin >> N;

  int arr[301] = {0, };
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  int dp[301] = {0, };
  // An = max(An-1, An-2 + a
  for (int i = 1; i <= N; i++) {
    if (i <= 2) {
      dp[i] = dp[i - 1] + arr[i];
      continue ; 
    }
    int a = dp[i - 2] + arr[i];
    int b = dp[i - 3] + arr[i - 1] + arr[i]; 
    dp[i] = max(a, b);
  } 
  cout <<dp[N] << endl;
}