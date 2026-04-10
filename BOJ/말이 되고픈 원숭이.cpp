#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

// 가로, 세로
int W,H;

// 나이트 처럼 이동 가능한 횟수
int K;

int map[201][201];

int visited[201][201][31];

int bfs(void) {

    struct Node {
        int y;
        int x;
        int time;
        int k;
    };

    queue<Node> q;
    q.push({1, 1, 0, K});
    visited[0][0][K] = 1;
    
    while (!q.empty()) {
        struct Node cur;
        cur = q.front();
        int y = cur.y;
        int x = cur.x;
        int time = cur.time;
        int k = cur.k;
        q.pop();

        if (y == H && x == W) {
            return time;
        }
        // 이동
        // 동서남북
        // 나이트 처럼 이동

        {
            int dy[4] = {0, -1, 0, +1};
            int dx[4] = {-1, 0, +1, 0};
            for (int i = 0; i < 4; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];
                if (yy < 1 || yy > H) {
                    continue ;
                }
                if (xx < 1 || xx > W) {
                    continue ;
                }
                if (map[yy][xx]) {
                    continue ;
                }
                if (visited[yy][xx][k])
                    continue ;
                q.push({yy, xx, time + 1, k});
                visited[yy][xx][k] = 1;
            }
        }

        if (k == 0) {
            continue ;
        }
        k--;

        {
            int dy[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
            int dx[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
            for (int i = 0; i < 8; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];
                if (yy < 1 || yy > H) {
                    continue ;
                }
                if (xx < 1 || xx > W) {
                    continue ;
                }
                if (map[yy][xx]) {
                    continue ;
                }
                if (visited[yy][xx][k])
                    continue ;
                q.push({yy, xx, time + 1, k});
                visited[yy][xx][k] = 1;
            }
        }
    }

    return -1;
}

int main() {
    cin >> K;
    cin >> W >> H;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> map[i][j];
        }   
    }


    int min_time;
    min_time = bfs();

    cout << min_time << endl;
}