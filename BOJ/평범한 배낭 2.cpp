#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 물건 종류, 배낭 최대 무게
    int N, M; 
    cin >> N >> M;


    // 가치와 무게가 같은 item 이 여러개 있고 이중 n 개를 선택할때, 이진분할을 활용 할수있다. 
    // K = 13 이라면
    // 1, 2, 4, 6 으로 나눈뒤 13 이라는 상태를 만들수있다.. 
    // 0000 ~ 1111 으로 13이라는 상태를 나타낼수있다.  
    // 1개 {1}
    // 2개 {2}
    // 3개 {1, 2}
    // 4개 {4}
    // 5개 {1, 4}
    // 6개 {2, 4}
    // 7개 {1, 2, 4}
    // 8개 {2, 6}
    // 9개 {1, 2, 6}
    // 10개 {4, 6}
    // 11개 {1, 4, 6}
    // 12개 {2, 4, 6}
    // 13개 {1, 2, 4, 6}

    vector<pair<int, int>> item;
    for (int i = 1; i <= N; i++) {
        // 물건 무게, 만족도, 갯수
        int V, C, K;
        cin >> V >> C >> K;
        // 이진 분할
        int cnt = 1;
        while (K) {
            int g = min(cnt, K);
            item.push_back({g * V, g * C});
            K -= g;
            cnt *= 2;
        }
    }

    vector<int> dp(M+1, 0);
    for (int i = 0; i < item.size(); i++) {
        for (int j = M; j >= 1; j--) {
            int w = item[i].first;
            int v = item[i].second;
            
            if (j < w) {
                continue;
            }
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[M] << endl;
}