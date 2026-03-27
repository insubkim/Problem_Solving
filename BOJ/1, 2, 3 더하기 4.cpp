#include <iostream>

using namespace std;

int dp[10001] = {0, };

void    solve(void)
{
    dp[0] = 1;

    // 1
    for (int i = 1; i <= 10000; i++) {
        dp[i] += dp[i - 1];
    }

    // 2
    for (int i = 2; i <= 10000; i++) {
        dp[i] += dp[i - 2];
    }

    // 3
    for (int i = 3; i <= 10000; i++) {
        dp[i] += dp[i - 3];
    }
}

int main()
{
    int N;

    cin >> N;

    solve();

    while (N--)
    {
        int t;

        cin >> t;
        
        cout << dp[t] << endl;
    }
    
    return 0;
}