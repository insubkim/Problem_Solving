#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int dp[101][101] = {0, };

    for (int i = 1; i < 101; i++)
    {
        dp[1][i] = 1;
        dp[i][1] = 1;
    }

    for (auto &x: puddles)
    {
        dp[x[1]][x[0]] = -1;
    }

    for (int i = 2; i < 101; i++)
    {
        for (int j = 2; j < 101; j++)
        {
            if (dp[i][j] == -1) continue;

            dp[i][j] = dp[i - 1][j] == -1 ? 0 : dp[i - 1][j]
                      + dp[i][j - 1] == -1 ? 0 : dp[i][j - 1];
            dp[i][j] %=  1000000007;
        }
    }


    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << dp[i][j];
        }   
        cout << endl;
    }

    answer = dp[n][m];
    return answer;
}

int main()
{
	vector<vector<int>> p;

	vector<int> k;
	k.push_back(2);
	k.push_back(2);
	p.push_back(k);
	solution(4,3,p);

}
