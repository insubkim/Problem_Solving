#include <iostream>
#include <vector>

using namespace std;

// 팰린드롬 판별 대상 수, 질문 수
int N, M;

// 팰린드롬 판별 대상
int seq[2001];

// i ~ j 가 팰린드롬이면 true
bool    dp[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> seq[i];
    }

    // 팰린드롬 판별
    for (int dist = 0; dist <= N; dist++) {
        for (int i = 1; i <= N; i++) {
            int j = i + dist;
            if (j > N) {
                break ;
            }

            if (dist == 0) {
                dp[i][j] = true;
            }
            else if (dist == 1) {
                dp[i][j] = seq[i] == seq[j];
            }
            else { // 길이 3 이상
                 if (seq[i] != seq[j]) {
                    dp[i][j] = false;
                 } 
                 else {
                    dp[i][j] =  dp[i + 1][j - 1];
                 }
            }
        }
    }

    cin >> M;
    while (M--) {
        int start, end;
        cin >> start >> end;

        // 팰린드롬 출력
        cout << dp[start][end] << '\n';
    }

    return 0;
}