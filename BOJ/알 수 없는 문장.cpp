#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int dp[51] = {0, };
    string s;
    cin >> s;

    int N;
    cin >> N;
    string w[50];
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }

    int s_len = s.length();
    for (int i = 1; i <= s_len; i++) {
        // dp[i] 계산
        
    }

    cout << dp[s_len] << endl;
}