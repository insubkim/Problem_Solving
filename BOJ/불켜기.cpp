#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

#include <string.h>

using namespace std;

// 맵 크기, 불 켜진 곳 입력수
int N, M;

// 지도
int map[101][101];

// 방문 체크
int visited[101][101];

// 불 스위치 리스트 
vector<pair<int, int>> light[101][101];

int bfs(void) {
    int max_light_up = 1;

    // (1,1) bfs 시작
    // 불 킬수있으면 on
    // 방문 시도
    // 만약 불킨곳이 있으면 다시 bfs 시작
    
    map[1][1] = 1;
    bool new_light_up = true;
    while (new_light_up) {
        memset(visited, 0, sizeof(visited));
        new_light_up = false;

        queue<pair<int, int>> q;
        q.push({1, 1});
        visited[1][1] = 1;
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            // 불키기
            for (auto &v: light[y][x]) {
                int y = v.first;
                int x = v.second;
                if (map[y][x]) {
                    continue ;
                }
                map[y][x] = 1;
                max_light_up++;
                new_light_up = true;
            }
            light[y][x].clear();

            // 방문 시도
            int dy[4] = {0, -1, 0, +1};
            int dx[4] = {-1, 0, +1, 0};
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
                if (map[yy][xx] != 1) {
                    continue ;
                }
                visited[yy][xx] = 1;
                q.push({yy, xx});
            }

        }
    }
    
    return max_light_up;
}

int main() {
    cin >> N >> M;

    while (M--) {
        // (x, y)에서 (a, b) 불을 킬 수 있다는 뜻
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        light[y][x].push_back({b, a});
    }

    int max_light_up;
    max_light_up = bfs();
    cout << max_light_up << endl;
}