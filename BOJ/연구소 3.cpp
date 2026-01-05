#include <bits/stdc++.h>

using namespace std;

int N,M;
int maps[50][50];
int min_path = 2147483647;
int selected[10];

vector<array<int, 2>> virus;
int virus_cnt;

int dy[4] = {-1, +0, +1, +0};
int dx[4] = {+0, +1, +0, -1};

bool    OOB(int y, int x)
{
    if (y < 0 || y > N -1 
        || x < 0 || x > N - 1)
        return true;
    return false;
}

void    bfs(void)
{
    queue<array<int,3>> visit_list;

    for (int i = 0; i < M; i++)
    {
        if (selected[i])
            visit_list.push({virus[i][0], virus[i][1], 0});
    }


    int maps_new[50][50];
    memcpy(maps_new, maps, sizeof(maps));

    int max_visit_cnt = 0;

    while (visit_list.empty() == false)
    {
        int y = visit_list.front()[0];
        int x = visit_list.front()[1];
        int visit_cnt = visit_list.front()[2];
    
        visit_list.pop();
        max_visit_cnt = max(max_visit_cnt, visit_cnt);

        for (int i = 0; i < 4; i++)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (OOB(yy, xx))
                continue;

            if (maps_new[yy][xx] != 0)
                continue;
            
            maps_new[yy][xx] = 3;
            visit_list.push({yy, xx, visit_cnt + 1});
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (maps_new[i][j] == 0)
                return;
        }
    }

    min_path = min(min_path, max_visit_cnt);
}

void    select_virus(int round, int idx)
{
    if (round == M)
    {
        bfs();
        
        return;
    }

    for (int i = idx; i < M; i++)
    {
        selected[i] = 1;
        select_virus(round + 1, i + 1);
        selected[i] = 0;
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j] == 2)
            {
                virus_cnt++;
                virus.push_back({i, j});
            }
        }
    }

    select_virus(0, 0);

    if (min_path == 2147483647)
        min_path = -1;
    cout << min_path << endl;
}