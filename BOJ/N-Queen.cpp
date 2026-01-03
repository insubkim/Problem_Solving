#include <bits/stdc++.h>

using namespace std;

int N;
int maps[16][16];
int total_cnt;

bool    OOB(int y, int x)
{
    if (y < 0 || x < 0)
        return false;
    if (y >= N || x >= N)
        return false;
    return true;
}

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

    //         아래 오른쪽, 아래 왼쪽, 위 오른쪽, 위 왼쪽
    int dy[4] {+1      , +1     , -1     , -1};
    int dx[4] {+1      , -1     , +1     , -1};

    // 각 대각선 체크
    for (int i = 0; i < 4; i++)
    {
        int ddy = dy[i];
        int ddx = dx[i];

        while (OOB(y + ddy, x + ddx))
        {
            if (maps[y + ddy][x + ddx])
                return false;
            ddy += dy[i];
            ddx += dx[i];
        }
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