#include <string>
#include <vector>

#include <cmath>
#include <string.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int dp[501] = {0,};

    // new_dp[n] = max(dp[n - 1], dp[n - 2]) + triangle[j][n]


    dp[0] = triangle[0][0];
    int max_sum = dp[0];

    for (int i = 1; i < triangle.size(); i++)
    {
        int new_dp[501] = {0,};

        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0) 
                new_dp[j] = dp[j] + + triangle[i][j];
            else if (j == triangle[i].size() - 1)  
                new_dp[j] = dp[j - 1] + + triangle[i][j];
            else 
                new_dp[j] = max(dp[j - 1], dp[j]) + triangle[i][j];

            max_sum = max(new_dp[j], max_sum);
        }

        memcpy(dp, new_dp, sizeof(dp));
    }


    answer = max_sum;
    return answer;
}