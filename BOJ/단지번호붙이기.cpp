#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int map[26][26];

vector<int> complex_unit;

int bfs(void) {
    int complex_cnt = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 건물 찾기
            // bfs 실행
            // 방문시 0 으로 초기화
            // unit + 1

            if (map[i][j] == 0) {
                continue ;
            }

            queue<pair<int, int>> q;
            q.push({i, j});
            map[i][j] = 0;
            complex_cnt++;
            complex_unit.push_back(1);
            
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

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
                    if (map[yy][xx] == 0) {
                        continue ;
                    }

                    q.push({yy, xx});
                    map[yy][xx] = 0;
                    complex_unit[complex_cnt - 1]++;
                }
            }
        
        }
    }

    return complex_cnt;
}

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= N; j++) {
            map[i][j] = line[j - 1] - '0';
        }
    }

    int complex_cnt;
    complex_cnt = bfs();

    cout << complex_cnt << endl;
    sort(complex_unit.begin(), complex_unit.end());
    for (int i = 0; i < complex_cnt; i++) {
        cout << complex_unit[i] << endl;
    }

    return 0;
}