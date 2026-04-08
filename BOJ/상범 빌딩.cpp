#include <iostream>
#include <string>
#include <queue>
#include <tuple>

#include <string.h>

using namespace std;

// 층, 행, 열
int L,R,C;

int map[31][31][31];

int visited[31][31][31];

// 시작점
int start[3];

int bfs(void) {
    memset(visited, 0, sizeof(visited));

    queue<pair<tuple<int,int,int>,int>> q;
    q.push({{start[0], start[1], start[2]}, 0});
    visited[start[0]][start[1]][start[2]] = true;

    while (!q.empty()) {
        int h = std::get<0>(q.front().first);
        int y = std::get<1>(q.front().first);
        int x = std::get<2>(q.front().first);
        int time = q.front().second;
        q.pop();


        int dh[6] = {0, 0, 0, 0, -1, 1};
        int dy[6] = {0, -1, 0, +1, 0, 0};
        int dx[6] = {-1, 0, +1, 0, 0, 0};
        for (int i = 0; i < 6; i++) {
            int hh = h + dh[i];
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy < 1 || yy > R) {
                continue ;
            }
            if (xx < 1 || xx > C) {
                continue ;
            }
            if (hh < 1 || hh > L) {
                continue ;
            }
            if (visited[hh][yy][xx]) {
                continue ;
            }
            if (map[hh][yy][xx] == '#') {
                continue ;
            }
            if (map[hh][yy][xx] == 'E') {
                return time + 1;
            }
            q.push({{hh, yy, xx}, time + 1});
            visited[hh][yy][xx] = true;
        }

    }

    return -1;
}

int main() {
    while (true) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) {
            break ;
        }

        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= R; j++) {
                string line;
                cin >> line;
                for (int k = 1; k <= C; k++) {
                    map[i][j][k] = line[k - 1];
                    if (map[i][j][k] == 'S') {
                        start[0] = i;
                        start[1] = j;
                        start[2] = k;
                    }
                }
            }   
        }
        int min_time;
        min_time = bfs();
        if (min_time == -1) {
            cout << "Trapped!" << endl;
            continue ;
        }
        cout << "Escaped in " << min_time << " minute(s)." << endl;
    }
    return 0;
}