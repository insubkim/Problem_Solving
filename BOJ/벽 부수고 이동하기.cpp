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
    int visited[1001][1001][2] = {0,};

    // y, x, 방문한 칸 수, 벽 부셨는지
    queue<array<int,4>> visit_list; 

    visit_list.push({0,0,1,0});
    visited[0][0][0] = 1;
    if (0 == N && 0 == M)
        min_path = 1;

    while (visit_list.empty() == false)
    {
        array<int,4> cur_node;
        cur_node[0] = visit_list.front()[0];
        cur_node[1] = visit_list.front()[1];
        cur_node[2] = visit_list.front()[2];
        cur_node[3] = visit_list.front()[3];
        visit_list.pop();

        // 목적지 도착
        if (cur_node[0] == N - 1 && cur_node[1] == M - 1)
        {
            min_path = min(min_path, cur_node[2]);
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int y = cur_node[0] + dy[i];
            int x = cur_node[1] + dx[i];
            int visit_cnt = cur_node[2] + 1;
            int break_wall = cur_node[3];

            if (OOB(y,x)) continue;


            // break_wall 상태에서 오지 않았고 벽이 아니라면
            if (maps[y][x] == 0 && visited[y][x][break_wall] == 0)
            {
                visit_list.push({y, x, visit_cnt, break_wall});
                visited[y][x][break_wall] = 1;
            }
            // 벽인데 이전에 벽 부순적이 없고 벽 부수지 않은 상태에서 온적 없음.
            if (maps[y][x] == 1 && break_wall == 0 && visited[y][x][1] == 0)
            {
                break_wall = 1;
                visited[y][x][break_wall] = 1;
                visit_list.push({y, x, visit_cnt, break_wall});
            }

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

    bfs();

    cout << (min_path == 2147483647 ? -1 : min_path)  << endl;
}