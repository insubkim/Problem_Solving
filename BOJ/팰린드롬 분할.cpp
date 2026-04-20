#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 팰린드롬 판별 대상
string seq;

// i ~ j 가 팰린드롬이면 true
bool    dp[2501][2501];

int dp2[2501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> seq;

    seq = " " + seq;
    int N = seq.size();

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

    // 최소 분할 횟수 판단
    // dp2[1] = 1;
    // dp2[2] 는 dp2[1] + 1 이거나 dp[1][2] true 면 dp2[0] + 1
    //
    // dp2[n] 은 dp[n-1] + 1 이거나 
    // i 는 0 부터 n - 1 까지dp2[i] + 1 . 만약 dp[i + 1][n] 이 true 일경우


	dp2[1] = 1;
	for (int i = 1; i <= N; i++)
	{
		dp2[i] = dp2[i-1] +1;
		for (int j = 1; j < i; j++) 
		{
			if (dp[j][i]) {
				dp2[i] = min(dp2[j - 1] +1, dp2[i]);
			}
		}
	}
	cout << dp2[N] - 1 << '\n';


    return 0;
}
