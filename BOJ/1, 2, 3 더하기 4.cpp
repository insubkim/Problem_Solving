#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int t)
{
    // 3 이 0 ~ 최대값까지
    //  2 로 나눈값 + 1
    int result = 0;

    int dp[10001] = {0, };

    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 3; 

    for (int i = 4; i <= t; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[t];
}

int main()
{
    int N;

    cin >> N;
    while (N--)
    {
        int result = 0;
        int t;

        cin >> t;

        result = solve(t);
        
        cout << result << endl;
    }
    
}