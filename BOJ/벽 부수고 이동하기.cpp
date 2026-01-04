#include <bits/stdc++.h>

using namespace std;

int N,M;
int maps[1001][1001];
int min_path = 2147483647;

int dy[4] = {-1, +0, +1, +0};
int dx[4] = {+0, +1, +0, -1};

bool    OOB(int y, int x)
{
    if (y < 0 || y > N - 1 
        || x < 0 || x > M - 1)
        return true;
    return false;
}


void    bfs(void)
{
    int visited[1001][1001] = {0,};

    // y, x, ¹æ¹®ÇÑ Ä­ ¼ö
    queue<array<int,3>> visit_list; 

    visit_list.push({0,0,1});
    visited[0][0] = 1;

    while (visit_list.empty() == false)
    {
        array<int,3> cur_node;
        cur_node[0] = visit_list.front()[0];
        cur_node[1] = visit_list.front()[1];
        cur_node[2] = visit_list.front()[2];
        visit_list.pop();

        for (int i = 0; i < 4; i++)
        {
            int y = cur_node[0] + dy[i];
            int x = cur_node[1] + dx[i];
            int visit_cnt = cur_node[2] + 1;

            if (OOB(y,x)) continue;

            if (visited[y][x]) continue;
            
            if (maps[y][x] == 1) continue;

            // ¸ñÀûÁö µµÂø
            if (y == N - 1 && x == M - 1)
            {
                min_path = min(min_path, visit_cnt);
                return;
            }

            visit_list.push({y,x,visit_cnt});
            visited[y][x] = 1;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            
            maps[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (maps[i][j] == 1)
            {
                maps[i][j] = 0;
                bfs();
                maps[i][j] = 1;
            }
        }
    }

    bfs();

    cout << (min_path == 2147483647 ? -1 : min_path)  << endl;
}