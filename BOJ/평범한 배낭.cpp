#include <iostream>
#include <cmath>

using namespace std;

int dp[101][100001];
int item[101][2]; //무게, 가치

int main() {
  int N, K;
  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    cin >> item[i][0] >> item[i][1];
  }

  for (int i = 1; i <= N; i++) {
    int weight  = item[i][0];
    int value   = item[i][1];
    for (int j = 1; j <= K; j++) {
      if (j >= weight) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[N][K] << endl;
}