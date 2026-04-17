#include <iostream>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <queue>

#include <string.h>

using namespace std;


// 세로, 가로
int R, C;

int map[51][51];

// 공기 청정기 위치
int air_purify[2];

// 미세먼지 위치, 양
queue<tuple<int, int, int>>q;

// 모니터링 시간
int T;

void    bfs(void) {
    while (T--) {
        int q_size = q.size();

        // 먼지 확산
        // cur, new map 
        // cur map 에서 new map 으로 확산 먼지 더하기
        // cur map 에서 new map 으로 빠진 먼지 빼기
        // 대기큐에 있는 먼지 전부 발산

        int new_map[51][51];
        memcpy(new_map, map, sizeof(map));

        while (q_size--) {
            int y = get<0>(q.front());
            int x = get<1>(q.front());
            int dust = get<2>(q.front());
            q.pop();

            int dy[4] = {0, -1, 0, +1};
            int dx[4] = {-1, 0, +1, 0};
            for (int i = 0; i < 4; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];
                if (yy < 1 || yy > R) {
                    continue ;
                }
                if (xx < 1 || xx > C) {
                    continue ;
                }
                if (map[yy][xx] == -1) {
                    continue ;
                }
                // 먼지 확산
                new_map[yy][xx] += dust / 5;   
                // 기존 위치 먼지 뺴기
                new_map[y][x] -= dust / 5;
            }
        }

        // 공기 청정
        // 위 반시계 방향으로 밀기
        // 아래 시계 방향으로 밀기

        // R * 2 + C * 2 번 밀기
        // 위 순서대로 (1, 0) (0, -1) (-1, 0) (0, +1)
        // 아래 순서대로 (1, 0) (0, +1) (-1, 0) (0, -1)

        int up_dy[4] = {0, -1, 0, +1};
        int up_dx[4] = {1, 0, -1, 0};
        int down_dy[4] = {0, +1, 0, -1};
        int down_dx[4] = {1, 0, -1, 0};
        int y = air_purify[0] - 1;
        int x = air_purify[1];
        int idx = 0;
        int prev = 0;
        while (y != air_purify[0] - 2 || x != air_purify[1]) {
            y += up_dy[idx];
            x += up_dx[idx];
            if (y < 1 || y > R) {
                y -= up_dy[idx];
                idx++;
                continue ;
            }
            if (x < 1 || x > C) {
                x -= up_dx[idx];
                idx++;
                continue ;
            }
            int temp;
            temp = prev;
            prev = new_map[y][x];
            new_map[y][x] = temp;
        }
        y = air_purify[0];
        x = air_purify[1];
        prev = 0;
        idx = 0;
        while (y != air_purify[0] + 1 || x != air_purify[1]) {
            y += down_dy[idx];
            x += down_dx[idx];
            if (y < 1 || y > R) {
                y -= down_dy[idx];
                idx++;
                continue ;
            }
            if (x < 1 || x > C) {
                x -= down_dx[idx];
                idx++;
                continue ;
            }
            int temp;
            temp = prev;
            prev = new_map[y][x];
            new_map[y][x] = temp;
        }
        memcpy(map, new_map, sizeof(map));

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (map[i][j] > 0) {
                    q.push({i, j, map[i][j]});
                }
                // cout << map[i][j] << ' ';
            }
            // cout << '\n';
        }
            // cout << '\n';
            // cout << '\n';
            // cout << '\n';
    }
}

int main(void) {
    cin >> R >> C >> T;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1) {
                air_purify[0] = i;
                air_purify[1] = j;
            }
            else if (map[i][j] > 0) {
                q.push({i, j, map[i][j]});
            }
        }
    }

    bfs();

    int dust = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (map[i][j] > 0) {
                dust += map[i][j];
            }
        }
    }
    cout << dust << endl;
}