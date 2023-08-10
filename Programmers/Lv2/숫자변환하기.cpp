#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {
    int a = 0;
    fill (dp, dp + 1000001, 10000000);
    dp[x] = 0;
    for (int i = x; i <= y; i++){
        if (i + n <= y) dp[i + n] = min(dp[i] + 1, dp[i + n]);
        if (i * 2 <= y) dp[i * 2] = min(dp[i] + 1, dp[i * 2]);
        if (i * 3 <= y) dp[i * 3] = min(dp[i] + 1, dp[i * 3]);
    }
    a = dp[y];
    if (a == 10000000) return -1;
    return a;
}
#include <iostream>
int main(){
    cout << solution(10, 40, 5) << endl;
}