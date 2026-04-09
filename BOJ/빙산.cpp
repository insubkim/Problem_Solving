#include <iostream>
#include <queue>

#include <string.h>

using namespace std;

// 행, 열
int N,M;

int map[301][301];

int visited[301][301];

int start[2];

int bfs(void) {
    // 모든 빙산 방문
    // 방문 성공 확인
    // 성공했으면 빙산 녹이기
    // 1 반복

    int time = 0;

    while (true)
    {
        memset(visited, 0, sizeof(visited));
        memset(start, 0, sizeof(start));

        // 시작점 찾기
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {        
                if (map[i][j] != 0) {
                    start[0] = i;
                    start[1] = j;
                    goto break_loop;
                }
            }   
        } 
    break_loop:

        // 빙산 다 녹으면 종료
        if (start[0] == 0 && start[1] == 0) {
            return 0;
        }

        // 방문 시도
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            int dy[4] = {0, -1, 0, +1};
            int dx[4] = {-1, 0, +1, 0};
            for (int i = 0; i < 4; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];
            
                if (yy < 1 || yy > N) {
                    continue ;
                }
                if (xx < 1 || xx > M) {
                    continue ;
                }
                if (visited[yy][xx]) {
                    continue ;
                }
                if (map[yy][xx] == 0) {
                    continue ;
                }
                q.push({yy,xx});
                visited[yy][xx] = true;
            }
        }

        // 모든 빙산 방문 확인
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {        
                if (map[i][j] != 0 && visited[i][j] == false) {
                    return time;
                }
            }   
        }
        time++;
        // cout << "================" << endl;
        // 빙산 녹이기
        int new_map[301][301];
        memcpy(new_map, map, sizeof(new_map));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {        
                
                // cout << map[i][j]; 

                if (map[i][j] == 0) {
                    int dy[4] = {0, -1, 0, +1};
                    int dx[4] = {-1, 0, +1, 0};
                    
                    for (int k = 0; k < 4; k++) {
                        int y = i + dy[k];
                        int x = j + dx[k];

                        if (y < 1 || y > N) {
                            continue ;
                        }
                        if (x < 1 || x > M) {
                            continue ;
                        }
                        if (new_map[y][x] != 0) {
                            new_map[y][x]--;
                        }
                    }
                
                }
            }

            // cout << endl;
        
        }
        memcpy(map, new_map, sizeof(map));

    }
    return 0;
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }   
    }

    int min_time;
    min_time = bfs();

    cout << min_time << endl;
    return 0;
}