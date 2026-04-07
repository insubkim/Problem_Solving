#include <iostream>
#include <queue>
#include <tuple>
#include <string>

#include <string.h>

using namespace std;

// 행 열 수
int r,c;

//#, J, F, .
//벽, 지훈 위치, 불 위치, 길
char map[1001][1001];

char fire_snapshot[1001][1001][1001];

bool visited[1001][1001];

void    simulate_fire(void) {
    // 초기값 복사
    memcpy(fire_snapshot, map, sizeof(char) * 1001 * 1001);

    // 불 확산 시뮬
    bool fire_flag = true;
    int time = 0;
    while (fire_flag) {
        fire_flag = false;
        time++;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                fire_snapshot[time][i][j] = fire_snapshot[time - 1][i][j];

                if (fire_snapshot[time - 1][i][j] != 'F') {
                    continue ;
                }

                int dy[4] = {0, -1, 0, 1};
                int dx[4] = {-1, 0, +1, 0};
                for (int k = 0; k < 4; k++) {
                    int y, x;
                    y = i + dy[k];
                    x = j + dx[k];

                    if (y < 0 || y > r) {
                        continue;
                    }

                    if (x < 0 || x > c) {
                        continue;
                    }

                    if (fire_snapshot[time][y][x] != '.') {
                        continue ;
                    }
                    fire_snapshot[time][y][x] = 'F';
                    fire_flag = true;
                    }   
                }
        }
    }
}


int bfs(int y, int x) {
    // 시간별 화재 확산 시뮬레이션
    simulate_fire();
    
    // 지훈이 탈출 실행
    // 지훈 위치(y,x), 시간
    queue<tuple<int, int, int>> q;
    q.push({y, x, 0});
    visited[y][x] = true;
    
    while (!q.empty()) {
        tuple<int, int, int> cur;
        cur = q.front();
        q.pop();

        int y = std::get<0>(cur);
        int x = std::get<1>(cur);
        int time = std::get<2>(cur);
    
        int dy[4] = {0, -1, 0, 1};
        int dx[4] = {-1, 0, +1, 0};
        for (int i = 0; i < 4; i++) {
            int yy, xx;
            yy = y + dy[i];
            xx = x + dx[i];
            
            if (yy < 1 || yy > r) {
                return time + 1;
            }
            
            if (xx < 1 || xx > c) {
                return time + 1;
            }
            
            if (visited[yy][xx]) {
                continue ;
            }

            if (map[yy][xx] != '.') {
                continue ;
            }

            if (time <= 1000 && fire_snapshot[time][yy][xx] != '.') {
                continue ;
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
    int y,x; 
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

    int min_time;
    min_time = bfs(y, x);

    if (min_time == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << min_time << endl;
    }
}