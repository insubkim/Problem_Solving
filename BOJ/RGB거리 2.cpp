#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1e9

int main(void) {
    int N;

    cin >> N;

    int r,g,b;
    cin >> r >> g >> b;

    enum {
        RED = 0,
        GRE = 1,
        BLU = 2,
    };

    // 현 노드에서 r,g,b 선택시 최솟값
    int dp[3][3]; 
    // 처음 red 선택후 dp
    dp[RED][RED] = r;
    dp[GRE][RED] = INF;
    dp[BLU][RED] = INF;

    // 처음 GRE 선택후 dp
    dp[RED][GRE] = INF;
    dp[GRE][GRE] = g;
    dp[BLU][GRE] = INF;

    // 처음 BLU 선택후 dp
    dp[RED][BLU] = INF;
    dp[GRE][BLU] = INF;
    dp[BLU][BLU] = b;

    for (int i = 2; i <= N; i++) {
        int r,g,b;
        int prev[3][3];
        memcpy(prev, dp, sizeof(dp));
        
        cin >> r >> g >> b;
        if (i != N) {
            dp[RED][RED] = min(prev[GRE][RED], prev[BLU][RED]) + r;
        }
        dp[GRE][RED] = min(prev[RED][RED], prev[BLU][RED]) + g;
        dp[BLU][RED] = min(prev[RED][RED], prev[GRE][RED]) + b;

        dp[RED][GRE] = min(prev[GRE][GRE], prev[BLU][GRE]) + r;
        if (i != N) {
            dp[GRE][GRE] = min(prev[RED][GRE], prev[BLU][GRE]) + g;
        }
        dp[BLU][GRE] = min(prev[RED][GRE], prev[GRE][GRE]) + b;

        dp[RED][BLU] = min(prev[GRE][BLU], prev[BLU][BLU]) + r;
        dp[GRE][BLU] = min(prev[RED][BLU], prev[BLU][BLU]) + g;
        if (i != N) {
            dp[BLU][BLU] = min(prev[RED][BLU], prev[GRE][BLU]) + b;
        }
    }
    
    cout << min({dp[GRE][RED], dp[BLU][RED], dp[RED][GRE], dp[BLU][GRE], dp[RED][BLU], dp[GRE][BLU]}) << '\n';
}