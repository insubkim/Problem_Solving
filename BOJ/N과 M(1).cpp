#include <bits/stdc++.h>

using namespace std;

int N,M;

int selected[9];
int print[9];

void    solve(int round)
{
    if (round == M)
    {
        for (int i = 0; i < M; i++)
            cout << print[i] << (i == (M - 1) ? "" : " ");
        cout << "\n"; 
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (selected[i])
            continue;
        selected[i] = 1;  // 현재 넣을 숫자 사용중 표시
        print[round] = i; // 현재 라운드의 수열 숫자 추가
        solve(round + 1);

        selected[i] = 0; // 아까 넣은 숫자 미수용 표시
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            N = i; M = j;    
            solve(0);
        }   
    }
}