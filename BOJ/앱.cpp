#include <iostream>
#include <vector>


using namespace std;

// 앱 수, 확보할 바이트수
int N,M;

// 메모리, 비활성화 비용
int app[101][2];

int dp[10001];

int main() {
    cin >> N >> M;

    int total_cost = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> app[j][i];

            if (i == 1) {
                total_cost += app[j][i];
            }
        }
    }

    // 각 app 에 대해서
    // dp 실행
    // 비용 i 일때 최대 확보 가능한 메모리
    // dp[i] = max(dp[i], dp[i - c] + m)
    // 동일 앱은 한번만 포함시켜야합으로 뒤에서 부터 루프 실행
    for (int i = 1; i <= N; i++) {
        int mem = app[i][0];
        int cost = app[i][1];
        for (int j = total_cost; j >= cost; j--) {
            dp[j] = max(dp[j], dp[j - cost] + mem);
        }
    }

    int min_cost = 1e9;
    for (int i = 0; i <= total_cost; i++) {
        if (dp[i] >= M) {
            min_cost = min(i, min_cost);
        }
    }

    cout << min_cost << '\n';
    return 0;
}