#include <iostream>
#include <string>
#include <queue>
#include <tuple>

#include <string.h>

using namespace std;

// 테스트 케이스
int T;

// 맵 가로, 세로
int w,h;

// 초기 위치
int coord[2];

int map[1001][1001];

int visited[1001][1001];

// 불이 빈 공간에 언제 붙는지 저장
int fire_snapshot[1001][1001];

void    cal_fire_snapshot(void) {
    // 불 붙은곳 모두 큐 삽입
    // 최초 불붙은 시간 스냅샷에 저장
    memset(visited, 0, sizeof(visited));

    queue<tuple<int, int, int>> q;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (map[i][j] == '*') {
                q.push({i, j, 0});
                visited[i][j] = true;
                fire_snapshot[i][j] = 0;
            } else {
                fire_snapshot[i][j] = 2147483647;
            }
        }   
    }

    // bfs 실행
    while (!q.empty()) {
        int y = std::get<0>(q.front());
        int x = std::get<1>(q.front());
        int time = std::get<2>(q.front());
        q.pop();

        int dy[4] = {0, -1, 0, +1};
        int dx[4] = {-1, 0, +1, 0};
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (yy < 1 || yy > h) {
                continue ;
            }
            if (xx < 1 || xx > w) {
                continue ;
            }
            if (visited[yy][xx]) {
                continue ;
            }
            if (map[yy][xx] == '#') {
                continue ;
            }
            q.push({yy, xx, time + 1});
            visited[yy][xx] = true;
            fire_snapshot[yy][xx] = time + 1;
        }        

    }
}

int bfs(void) {
    // 불이 언제 빈공간으로 최초에 붙는지 계산
    // bfs
    // cal_fire
    cal_fire_snapshot();

    // 상근이 탈출 시도.
    // bfs
    memset(visited, 0, sizeof(visited));

    queue<tuple<int, int, int>> q;
    q.push({coord[0], coord[1], 0});
    visited[coord[0]][coord[1]] = true;

    while (!q.empty()) {
        int y = std::get<0>(q.front());
        int x = std::get<1>(q.front());
        int time = std::get<2>(q.front());
        q.pop();

        int dy[4] = {0, -1, 0, +1};
        int dx[4] = {-1, 0, +1, 0};
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (yy < 1 || yy > h) {
                return time + 1;
            }
            if (xx < 1 || xx > w) {
                return time + 1;
            }
            if (visited[yy][xx]) {
                continue ;
            }
            if (map[yy][xx] != '.') {
                continue ;
            }
            if (fire_snapshot[yy][xx] <= time + 1) {
                continue ;
            }
            q.push({yy, xx, time + 1});
            visited[yy][xx] = true;
        }
    }
    
    return -1;
}

int main() {
    cin >> T;

    while (T--) {
        cin >> w >> h;

        for (int i = 1; i <= h; i++) {
            string line;
            cin >> line;
            for (int j = 1; j <= w; j++) {
                map[i][j] = line[j - 1];
                if (map[i][j] == '@') {
                    coord[0] = i;
                    coord[1] = j;
                }
            }   
        }

        int min_time;
        min_time = bfs();
        if (min_time == -1) {
            cout << "IMPOSSIBLE" << endl;
            continue ;
        }
        cout << min_time << endl;
    }

    return 0;   
}