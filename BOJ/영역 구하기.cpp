#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#include <string.h>

using namespace std;

// 세로, 가로 길이
int M, N;

int K;

int map[101][101];

vector<int> areas;

int bfs(void) {
    int area_cnt = 0;
    
    // 빈 공간 확인
    // bfs 
    // area_cnt++
    while (true) {
        int y, x;
        y = -1;

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] == 0) {
                    y = i;
                    x = j;
                    goto break_loop;
                }
            }   
        }
    
break_loop:
        if (y == -1) {
            break ;
        }
        queue<pair<int, int>> q;
        q.push({y, x});
        map[y][x] = 1;
        int area = 0;
        area_cnt++;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            area++;

            int dy[4] = {0, -1, 0, +1};
            int dx[4] = {-1, 0, +1, 0};
            for (int i = 0; i < 4; i++) {
                int yy = y + dy[i];
                int xx = x + dx[i];

                if (yy < 1 || yy > M) {
                    continue ;
                }
                if (xx < 1 || xx > N) {
                    continue ;
                }
                if (map[yy][xx] != 0) {
                    continue ;
                }
                q.push({yy, xx});
                map[yy][xx] = 1;
            }
        }
        areas.push_back(area);
    }

    return area_cnt;
}

int main() {
    cin >> M >> N >> K;

    
    for (int i = 1; i <= K; i++) {
        int x1, x2;
        int y1, y2;

        cin >> x1 >> y1;
        cin >> x2 >> y2;

        x1++;
        y1++;

        for (int i = y1; i <= y2; i++) {
            for (int j = x1; j <= x2; j++) {
                map[i][j] = 1;
            }   
        }
    }

    int area_cnt;
    area_cnt = bfs();

    cout << area_cnt << endl;
    sort(areas.begin(), areas.end());

    for (auto x: areas) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}