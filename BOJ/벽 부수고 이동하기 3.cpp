#include <iostream>
#include <queue>
#include <string>

using namespace std;

// 가로, 세로
int N,M;

// 부술수있는 벽
int K;

int map[1001][1001];

int visited[1001][1001][11][2];

int bfs(void) {

    struct Node {
        int y;
        int x;
        int time;
        int k;
        int is_daytime;
    };

    queue<Node> q;
    q.push({1, 1, 1, K, 1});
    visited[1][1][K][1] = 1;
    
    while (!q.empty()) {
        struct Node cur;
        cur = q.front();
        int y = cur.y;
        int x = cur.x;
        int time = cur.time;
        int k = cur.k;
        int is_daytime = cur.is_daytime;
        q.pop();

        if (y == N && x == M) {
            return time;
        }
        // 이동
        // 동서남북
        // 나이트 처럼 이동

        int dy[4] = {0, -1, 0, +1};
        int dx[4] = {-1, 0, +1, 0};
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            int new_is_daytime = !is_daytime;
            if (yy < 1 || yy > N) {
                continue ;
            }
            if (xx < 1 || xx > M) {
                continue ;
            }

            if (map[yy][xx]) {
                if (k == 0) {
                    continue ;
                }
                if (visited[yy][xx][k - 1][new_is_daytime]) {
                    continue ;
                }
                // 밤이면 하루 기다리기
                // 낮이면 벽 부수기

                if (is_daytime == 0) {
                    // 낮 기다리기
                    if (visited[y][x][k][new_is_daytime]) {
                        continue ;
                    }
                    q.push({y, x, time + 1, k, new_is_daytime});
                    visited[y][x][k][new_is_daytime] = 1;
                } else {
                    q.push({yy, xx, time + 1, k - 1, new_is_daytime});
                    visited[yy][xx][k - 1][new_is_daytime] = 1;
                }
            } else {
                if (visited[yy][xx][k][new_is_daytime]) {
                    continue ;
                }
                
                q.push({yy, xx, time + 1, k, new_is_daytime});
                visited[yy][xx][k][new_is_daytime] = 1;
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++) {
            map[i][j] = line[j - 1] - '0';
        }   
    }

    int min_time;
    min_time = bfs();

    cout << min_time << endl;
}