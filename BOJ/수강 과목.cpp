#include <iostream>

using namespace std;

// 시간, 과목 수
int N, K;

// 과목 중요도, 공부 시간
int subject[1001][2];

int dp[1001][10001];

int main(void) {
    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        cin >> subject[i][0] >> subject[i][1];
    }

    for (int i = 1; i <= K; i++) {
        int priority = subject[i][0];
        int time = subject[i][1];
        for (int j = 1; j <= N; j++) {
            if (j < time) {
                dp[i][j] = dp[i - 1][j];
                continue ;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time] + priority);
        }
    }

    cout << dp[K][N] << '\n';
}