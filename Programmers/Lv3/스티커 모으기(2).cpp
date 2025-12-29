#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;

    if (sticker.size() == 1) return sticker[0];
    else if (sticker.size() == 2) return max(sticker[0], sticker[1]);

    int dp[100000] = {0,};
    dp[0] = sticker[0];
    dp[1] = max(sticker[0], sticker[1]);

    int dp2[100000] = {0,};
    dp2[0] = 0;
    dp2[1] = sticker[1];
    dp2[2] = max(sticker[1], sticker[2]);

    for (int i = 2; i < sticker.size() - 1; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);        
    }

    dp2[sticker.size() - 1] = max(dp2[sticker.size() - 2], dp2[sticker.size() - 3] + sticker[sticker.size() - 1]);

    answer = max(dp[sticker.size() - 2], dp2[sticker.size() - 1]);
    return answer;
}
