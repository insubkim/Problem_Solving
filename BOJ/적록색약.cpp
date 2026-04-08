#include <iostream>
#include <string>
#include <queue>

#include <string.h>

using namespace std;

int N;

int map[101][101];

int visited[101][101];

int bfs(void) {
    // 1,1 시작 ~ N,N 까지 순회하며 visit 실행
    // visited 아니면 cnt 증가
    // 인접면 전부 visit 처리

    memset(visited, 0, sizeof(visited));
    
    int area_cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i][j]) {
                continue ;
            }
            area_cnt++;
            // bfs 실행

            int area = map[i][j];
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                int dy[4] = {0, -1 ,0, +1};
                int dx[4] = {-1, 0 ,+1, 0};
                for (int i = 0; i < 4; i++) {
                    int yy = y + dy[i];
                    int xx = x + dx[i];

                    if (yy < 1 || yy > N) {
                        continue ;
                    }

                    if (xx < 1 || xx > N) {
                        continue ;
                    }

                    if (visited[yy][xx]) {
                        continue ;
                    }

                    if (map[yy][xx] != area) {
                        continue ;
                    }

                    q.push({yy, xx});
                    visited[yy][xx] = true;
                }

            }

        }   
    }
    return area_cnt;
}

int bfs2(void) {
    // 1,1 시작 ~ N,N 까지 순회하며 visit 실행
    // visited 아니면 cnt 증가
    // 인접면 전부 visit 처리

    memset(visited, 0, sizeof(visited));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }   
    }

    int area_cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i][j]) {
                continue ;
            }
            area_cnt++;
            // bfs 실행

            int area = map[i][j];
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                int dy[4] = {0, -1 ,0, +1};
                int dx[4] = {-1, 0 ,+1, 0};
                for (int i = 0; i < 4; i++) {
                    int yy = y + dy[i];
                    int xx = x + dx[i];

                    if (yy < 1 || yy > N) {
                        continue ;
                    }

                    if (xx < 1 || xx > N) {
                        continue ;
                    }

                    if (visited[yy][xx]) {
                        continue ;
                    }

                    if (map[yy][xx] != area) {
                        continue ;
                    }

                    q.push({yy, xx});
                    visited[yy][xx] = true;
                }

            }

        }   
    }
    return area_cnt;
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= N; j++) {
            map[i][j] = line[j - 1];
        }   
    }

    // rgb 구별
    int rgb_cnt;
    rgb_cnt = bfs();
    
    // {r,g}, b 구별
    int rg_b_cnt;
    rg_b_cnt = bfs2();

    cout << rgb_cnt << ' ' << rg_b_cnt << endl;
}