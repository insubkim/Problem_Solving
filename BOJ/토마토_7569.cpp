#include <iostream>
#include <string>
#include <queue>
#include <tuple>

#include <string.h>

using namespace std;

// 가로, 세로, 층 수
int M,N,H;

// 토마토 위치 (0 안 익음, 1 익음, -1 없음)
int map[101][101][101];

bool visited[101][101][101];


// bfs큐, 토마토 위치 (y,x,h), 시간 
queue<pair<tuple<int, int, int>, int>> q;

int bfs(void) {
    int min_time = 0;

    while (!q.empty()) {
        tuple<int,int,int> t = q.front().first;
        int h = std::get<0>(t);
        int y = std::get<1>(t);
        int x = std::get<2>(t);
        int time = q.front().second;
        q.pop();

        int dy[6] = {0, -1, 0, +1, 0, 0};
        int dx[6] = {-1, 0, +1, 0, 0, 0};
        int dh[6] = {0, 0, 0, 0, -1, 1};
        for (int i = 0; i < 6; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            int hh = h + dh[i];
            if (yy < 1 || yy > N) {
                continue ;
            }
            if (xx < 1 || xx > M) {
                continue ;
            }
            if (hh < 1 || hh > H) {
                continue ;
            }
            if (visited[hh][yy][xx]) {
                continue ;
            }
            if (map[hh][yy][xx] == -1) {
                continue ;
            }
            map[hh][yy][xx] = 1;
            visited[hh][yy][xx] = true;
            q.push({{hh, yy, xx}, time + 1});
            min_time = time + 1;


        }
    }
    
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                if (map[i][j][k] == 0) {
                    return -1;
                }
            }
        }   
    }
    return min_time;
}

int main() {
    cin >> M >> N >> H;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                cin >> map[i][j][k];
                
                if (map[i][j][k] == 1) {
                    q.push({{i, j, k}, 0});
                    visited[i][j][k] = true;
                }
            }
        }
    }

    int min_time;
    min_time = bfs();

    cout << min_time << endl;

    return 0;
}