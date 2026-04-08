#include <iostream>
#include <vector>


using namespace std;

int main() {
    // 앱 수, 확보할 바이트수
    int N,M;
    cin >> N >> M;

    // 사용 메모리, 비용
    vector<pair<int, int>> apps;
    for (int i = 0; i < N; i++) {
        int m,c;
        cin >> m >> c;
        apps.push_back({m, c});
    }

    // i 번째 app 을 활성 혹은 비활성화 하고 확보 필요 바이트가 m 일때 최소 비용
    vector<unsigned long long>dp (M + 1, 0);
    for (int i = 0; i < apps.size(); i++) {
        for (int j = M; j >= 0; j--) {
            if (j < apps[i].first) {
                continue;
            }
            dp[i] = min(dp[i], dp[i - j] + apps[i].second);
        }
    }

    cout << dp[M] << endl;
}