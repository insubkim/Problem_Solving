#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> s) {
    long long p_a = 0;
    int p = 1;
    vector<long long> p_s(begin(s), end(s));
    for (auto &x : p_s){
        x *= p;
        p *= -1;
    }
    vector<long long> p_dp = p_s;
    for (int i = 0; i < (int)p_dp.size(); i++){
        if (i == 0){
            p_a = p_dp[0];
            continue ;
        }
        if (p_dp[i] < p_dp[i - 1] + p_dp[i]){
            p_dp[i] = p_dp[i - 1] + p_dp[i];
        }
        if (p_a < p_dp[i])
            p_a = p_dp[i];
    }

    long long n_a = 0;
    vector<long long> n_s(begin(s), end(s));
    p = -1;
    for (auto &x : n_s){
        x *= p;
        p *= -1;
    }
    vector<long long> n_dp = n_s;
    for (int i = 0; i < (int)n_dp.size(); i++){
        if (i == 0){
            n_a = n_dp[0];
            continue ;
        }
        if (n_dp[i] < n_dp[i - 1] + n_dp[i]){
            n_dp[i] = n_dp[i - 1] + n_dp[i];
        }
        if (n_a < n_dp[i])
            n_a = n_dp[i];
    }
    return p_a > n_a ? p_a : n_a;
}