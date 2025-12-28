#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    unsigned long long answer = 0;

    // n = 1 1
    // n = 2 2
    // n = * dp[n-1] + dp[n-2]

    if (n == 1) return 1;
    else if (n == 2) return 2;

    unsigned long long dp_prev = 2;
    unsigned long long dp_prev_prev = 1;

    for (int i = 2; i < n; i++)
    {
        unsigned long long new_dp = (dp_prev_prev + dp_prev)% 1000000007;
        dp_prev_prev = dp_prev;
        dp_prev = new_dp;
    }

    answer = dp_prev;
 
    return answer % 1000000007;
}