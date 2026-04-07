#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <string.h>

using namespace std;

// 행 열 수
int r, c;

// #, J, F, .
// 벽, 지훈 위치, 불 위치, 길
char map[1001][1001];

bool visited[1001][1001];

// 각 칸에 불이 처음 도착하는 시간
// -1이면 불이 오지 않음
int fire_time[1001][1001];

void simulate_fire(void) {
    queue<pair<int, int>> q;

    memset(fire_time, -1, sizeof(fire_time));

    // 초기 불 위치 전부 큐에 삽입
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (map[i][j] == 'F') {
                q.push({i, j});
                fire_time[i][j] = 0;
            }
        }
    }

    // 불 BFS
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int y = cur.first;
        int x = cur.second;

        int dy[4] = {0, -1, 0, 1};
        int dx[4] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++) {
            int yy = y + dy[k];
            int xx = x + dx[k];

            if (yy < 1 || yy > r) {
                continue;
            }
            if (xx < 1 || xx > c) {
                continue;
            }

            if (map[yy][xx] == '#') {
                continue;
            }

            if (fire_time[yy][xx] != -1) {
                continue;
            }

            fire_time[yy][xx] = fire_time[y][x] + 1;
            q.push({yy, xx});
        }
    }
}

int bfs(int y, int x) {
    // 시간별 화재 확산 시뮬 대신
    // 각 칸에 불 도착 시간을 계산
    simulate_fire();

    // 지훈이 탈출 실행
    // 지훈 위치(y,x), 시간
    queue<tuple<int, int, int>> q;
    q.push({y, x, 0});
    visited[y][x] = true;

    while (!q.empty()) {
        tuple<int, int, int> cur = q.front();
        q.pop();

        int cy = get<0>(cur);
        int cx = get<1>(cur);
        int time = get<2>(cur);

        int dy[4] = {0, -1, 0, 1};
        int dx[4] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int yy = cy + dy[i];
            int xx = cx + dx[i];

            // 맵 밖으로 나가면 탈출 성공
            if (yy < 1 || yy > r) {
                return time + 1;
            }
            if (xx < 1 || xx > c) {
                return time + 1;
            }

            if (visited[yy][xx]) {
                continue;
            }

            if (map[yy][xx] != '.') {
                continue;
            }

            // 지훈이 다음 칸에 time+1 에 도착
            // 불이 그보다 먼저 오거나 동시에 오면 못 감
            if (fire_time[yy][xx] != -1 && fire_time[yy][xx] <= time + 1) {
                continue;
            }

            q.push({yy, xx, time + 1});
            visited[yy][xx] = true;
        }
    }

    return -1;
}

int main() {
    cin >> r >> c;

    // 지훈 위치
    int y, x;
    for (int i = 1; i <= r; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= c; j++) {
            map[i][j] = line[j - 1];
            if (map[i][j] == 'J') {
                y = i;
                x = j;
            }
        }
    }

    int min_time = bfs(y, x);

    if (min_time == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << min_time << endl;
    }
}