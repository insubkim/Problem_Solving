#include <iostream>

using namespace std;

int N, T;

int dp[101][10001];

// 공부 시간, 배점
int unit[101][2];

int main(void) {
    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        cin >> unit[i][0] >> unit[i][1];
    }

    // i 번째 단원까지 고려하고 최대 공부 시간이 j 일때 최대 점수
    for (int i = 1; i <= N; i++) {
        int time = unit[i][0];
        int score = unit[i][1];
        for (int  j = 1; j <= T; j++) {
            if (j < time) {
                dp[i][j] = dp[i - 1][j];
                continue ;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time] + score);
        }   
    }

    cout <<dp[N][T] << '\n';

    return 0;
}