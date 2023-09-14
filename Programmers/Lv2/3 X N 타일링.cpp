#include <string>
#include <vector>

using namespace std;

vector<int> dp(2500);


int solution(int n) {
    long long a;
    //f(n - 2) * 3 + f(n - 4) * 2 + f(2) * 2 + 2;
    dp.push_back(3);
    long long sum = 3 * 2;
    for(int i = 4; i <= n; i += 2){
        a = sum;
        a += dp[dp.size() - 1] + 2;
        a %= 1000000007;
        dp.push_back(a);
        sum += (a * 2) % 1000000007;
    }
    return dp[dp.size() - 1];
}