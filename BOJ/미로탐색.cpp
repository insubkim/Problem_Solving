#include <iostream>
#include <queue>

using namespace std;

// 세로, 가로
int n,m;

// 맵
int map[101][101];

// 방문한 위치
int visited[101][101];

int bfs(void) {
    queue<tuple<int, int, int>> q;
    q.push({1, 1, 1});
    visited[1][1] = 1;

    while (!q.empty()) {
        tuple<int, int, int> coord = q.front();
        q.pop();
        int y = std::get<0>(coord);
        int x = std::get<1>(coord);
        int path_cnt = std::get<2>(coord);
        if (y == n && x == m) {
            return path_cnt;
        }

        int dy[4] = {0, -1, 0, 1};
        int dx[4] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
        
            if (1 > yy || n < yy)
                continue;
            if (1 > xx || m < xx)
                continue;
        
            if (map[yy][xx] == 0)
                continue;

            if (visited[yy][xx] == 1)
                continue;

            q.push({yy, xx, path_cnt + 1});
            visited[yy][xx] = 1;
        }
    }


    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c;
            cin >> c;
            map[i][j] = c;
        }   
    }
    
    int path_cnt = bfs();
    
    cout << path_cnt << endl;
}