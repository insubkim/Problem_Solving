#include <bits/stdc++.h>

using namespace std;

// M 가로, N 세로
int M,N;
int maps[1001][1001];

int max_depth;

queue<array<int,3>> visit_list;

int dy[4] = {-1, +0, +1 ,+0};
int dx[4] = {+0, +1, +0 ,-1};

bool    OOB(int y, int x)
{
    if (y < 0 || y > N - 1 
        || x < 0 || x > M - 1)
        return true;
    return false;
}

void    bfs(void)
{
    max_depth = 0;

    while (visit_list.empty() == false)
    {
        int y = visit_list.front()[0];
        int x = visit_list.front()[1];
        int date = visit_list.front()[2];
        visit_list.pop();

        max_depth = max(max_depth, date);

        for (int i = 0; i < 4; i++)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (OOB(yy, xx)) continue;

            if (maps[yy][xx] != 0) continue;

            maps[yy][xx] = 1;
            visit_list.push({yy, xx, date + 1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j] == 1)
                visit_list.push({i, j, 0});
        }
    }

    // 각 익은 토마토 지점에서 bfs 실행.
    // bfs max depth 수집
    bfs();

    // // 안익은 토마토 있는지 확인
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (maps[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << max_depth << endl;
}