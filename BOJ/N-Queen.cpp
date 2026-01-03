#include <bits/stdc++.h>

using namespace std;

int N;
int maps[16][16];
int total_cnt;

bool    checkmate(int y, int x)
{
    // 가로 세로 체크
    for (int i = 0; i < N; i++)
    {
        // i 행 x 열 퀸 체크 
        if (maps[i][x])
            return false;
        // y 행 i 열 퀸 체크 
        if (maps[y][i])
            return false;   
    }

    // 오른쪽 아래 대각 체크
    int dy = 1;
    int dx = 1;
    for (int i = 0; i < N; i++)
    {
        if (y + dy >= N || x + dx >= N)
        {
            break;
        }
        if (maps[y + dy][x + dx])
            return false; 
        dy++;
        dx++;
    }

    // 오른쪽 위 대각 체크
    dy = -1;
    dx = 1;
    for (int i = 0; i < N; i++)
    {
        if (y + dy < 0 || x + dx >= N)
        {
            break;
        }
        if (maps[y + dy][x + dx])
            return false; 
        dy--;
        dx++;
    }

    // 왼쪽 아래 대각 체크
    dy = 1;
    dx = -1;
    for (int i = 0; i < N; i++)
    {
        if (y + dy >= N || x + dx < 0)
        {
            break;
        }
        if (maps[y + dy][x + dx])
            return false;
        dy++;
        dx--;
    }

    // 왼쪽 위 대각 체크
    dy = -1;
    dx = -1;
    for (int i = 0; i < N; i++)
    {
        if (y + dy < 0 || x + dx < 0)
        {
            break;
        }
        if (maps[y + dy][x + dx])
            return false;
        dy--;
        dx--;
    }

    return true;
}

void    solve(int round)
{
    if (round == N)
    {
        total_cnt++;
        return ;
    }

    for (int i = 0; i < N; i++)
    {
        int y = round;
        int x = i;
        if (checkmate(y, x))
        {
            maps[y][x] = 1;
            solve(round + 1);
            maps[y][x] = 0;
        }
    }

}

int main()
{
    cin >> N;

    solve(0);

    cout << total_cnt << endl;
}