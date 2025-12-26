#include <string>
#include <vector>

using namespace std;

#define INF 2147483647

int solution(vector<vector<int>> info, int n, int m) {
    vector<int> dp(121, INF);
    
    // 흔적 제로 일떄는 시작점으로 설정  
    dp[0] = 0;
    
    // dp는  첨자에는 b의 흔적. 그리고 해당 원소는 a 의 최솟값
    // dp[i] 가 inf가 아닌 모든 값에 대해, 
    // info[k][0] a 가 흔적을 남기는 경우, info[k][1] b 가 흔적을 남기는 경우를 각각 계산 하여 작은 값 계산
    
    // 모든 항목 흔적 계산
    for (int i = 0; i < info.size(); i++)
    {
        vector<int> new_dp(121, INF);

        for (int j = 0; j < m; j++)
        {
            if (dp[j] == INF) continue;
            
            int a_trace = info[i][0];
            int b_trace = info[i][1];
            
            // b 가 훔침
            if (j + b_trace < m)
            {
                // 기존 상태랑 현재 상태에서 훔친거랑 비교 후 갱신
                new_dp[j + b_trace] = min(dp[j], new_dp[j + b_trace]);
            }

            // a 가 훔침
            if (dp[j] + a_trace < n)
            {     
                // 기존 상태랑 현재 상태에서 a가 훔친거랑 비교 후 갱신
                new_dp[j] = min(dp[j] + a_trace, new_dp[j]);
            }
        }
        dp = new_dp;
    }

    int min_a = INF;
    for (auto &x: dp)
        min_a = min(min_a, x);
    
    if (min_a == INF)
        return -1;
    return min_a;
}