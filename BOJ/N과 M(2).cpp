#include <bits/stdc++.h>

using namespace std;

int N,M;

int print[9];

void    solve(int round, int prev)
{
    if (round == M)
    {
        for (int i = 0; i < M; i++)
            cout << print[i] << (i == (M - 1) ? "" : " ");
        cout << "\n"; 
        return;
    }

    for (int i = prev + 1; i <= N; i++)
    {
        print[round] = i; // 현재 라운드의 수열 숫자 추가
        solve(round + 1, i);

    }
}

int main()
{
    cin >> N >> M;
 
    solve(0, 0);
}