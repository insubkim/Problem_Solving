#include <iostream>

using namespace std;

int main() {
    int c; 
    int city_cnt;
    cin >> c >> city_cnt;

    int dp[1101] = {0, };
    fill(dp, dp + 1101, 1e9);
    dp[0] = 0;

    for (int i = 0; i < city_cnt; i++) {
        int cost;
        int customer;
        cin >> cost >> customer;
        for (int j = customer; j <= c + 100; j++) {
            dp[j] = min(dp[j], dp[j - customer] + cost);
        }
    }

    int ans = 1e9;
    for (int i = c; i <= c + 100; i++) {    
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}