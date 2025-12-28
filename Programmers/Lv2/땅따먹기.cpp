#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int max_three(int a, int b, int c)
{
    return max(a, max(b, c));
}

int solution(vector<vector<int>> land)
{
    int answer = 0;

    // dp[0] = land[j][0] + max( dp[1], dp[2],dp[3])  
    // dp[1] = land[j][1] + max( dp[0], dp[2],dp[3])
    // dp[2] = land[j][2] + max( dp[0], dp[1],dp[3])
    // dp[3] = land[j][3] + max( dp[0], dp[1],dp[2])

    int dp[4] = {0,};


    dp[0] = land[0][0];
    dp[1] = land[0][1];
    dp[2] = land[0][2];
    dp[3] = land[0][3];

    for (int i = 1; i < land.size(); i++)
    {
        int dp_new[4];
        memcpy(dp_new, dp, sizeof(dp_new));

        dp[0] = land[i][0] + max_three(dp_new[1], dp_new[2], dp_new[3]);
        dp[1] = land[i][1] + max_three(dp_new[0], dp_new[2], dp_new[3]);
        dp[2] = land[i][2] + max_three(dp_new[0], dp_new[1], dp_new[3]);
        dp[3] = land[i][3] + max_three(dp_new[0], dp_new[1], dp_new[2]);
    }

    answer = max(max_three(dp[0], dp[1], dp[2]), dp[3]);

    return answer;
}