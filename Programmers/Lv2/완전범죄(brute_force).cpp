#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a_least = 2147483647;

bool    cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
} 

void    solve(vector<vector<int>> &info, int n, int m, int round, vector<int> select)
{
    int a_trace = 0;
    int b_trace = 0;

    for (int i = 0; i < round; i++)
    {
        if (select[i] == 0) a_trace += info[i][0];
        else b_trace += info[i][1];
    }
     
    if (n <= a_trace || m <= b_trace)
        return ;

    if (round == info.size())
    {
        a_least = a_trace < a_least ? a_trace : a_least; 
        return ;
    }
    select[round] = 0;
    solve(info, n, m, round + 1, select);

    select[round] = 1;
    solve(info, n, m, round + 1, select);

}

int solution(vector<vector<int>> info, int n, int m) {
    int answer;
    vector<int> select(40, 0);

    sort(info.begin(), info.end(), cmp);

    // brute force
    solve(info, n, m, 0, select);

    answer = a_least == 2147483647 ? -1 : a_least; 

    return answer;
}


