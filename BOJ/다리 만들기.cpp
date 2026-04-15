#include <iostream>
#include <queue>
#include <tuple>

#include <string.h>

using namespace std;

// 가로, 세로
int N;

int map[101][101];

void    distict_land(void) {
    // 땅 찾기
    // bfs 실행

    int land_no = 2;
    while (true) {
        int y, x;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] == 1) {
                    y = i;
                    x = j;
                    goto break_loop;
                }
            }   
        }
        // 전부 방문시 중단
        break;
break_loop:
        // bfs 실행하여 land 번호 수정
        int visited[101][101] = {{0 }, };

        queue<pair<int, int>> q;
        q.push({y, x});
        visited[y][x] = 1;
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            map[y][x] = land_no;

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
                if (map[yy][xx] == 0) {
                    continue ;
                }
                q.push({yy, xx});
                visited[yy][xx] = 1;
            }
        }


        // 다음 land 번호 갱신
        land_no++;
    }
}

int bfs(void) {
    int min_bridge_length = 2147483647;
    
    // 대륙과 인접한 바다찾기
    // bfs 실행하여 다른 대륙으로 이동 다리 길이 계산
    

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] != 0) {
                continue ;
            }

            // 대륙과 인접한 바다 확인
            bool is_near_land = false;
            int src_land_no = 0;
            int dy[4] = {0, -1, 0, +1};
            int dx[4] = {-1, 0, +1, 0};
            for (int k = 0; k < 4; k++) {
                int yy = i + dy[k];
                int xx = j + dx[k];
                if (yy < 1 || yy > N) {
                    continue ;
                }
                if (xx < 1 || xx > N) {
                    continue ;
                }
                if (map[yy][xx]) {
                    is_near_land = true;
                    src_land_no = map[yy][xx];
                    break ;
                }
            }
            if (!is_near_land) {
                continue ;
            }

            // bfs 실행하여 brige 생성
            int bridge_length = 0;
            bool found_other_land = false;
            
            int visited[101][101] = {{0 }, };
            queue<tuple<int, int, int>> q;
            q.push({i, j, 1});

            while (!q.empty()) {
                int y = get<0>(q.front());
                int x = get<1>(q.front());
                int length = get<2>(q.front());
                q.pop();

                int dy[4] = {0, -1, 0, +1};
                int dx[4] = {-1, 0, +1, 0};
                for (int k = 0; k < 4; k++) {
                    int yy = y + dy[k];
                    int xx = x + dx[k];
                    if (yy < 1 || yy > N) {
                        continue ;
                    }
                    if (xx < 1 || xx > N) {
                        continue ;
                    }
                    if (visited[yy][xx]) {
                        continue ;
                    }
                    if (map[yy][xx] == src_land_no) {
                        continue ;
                    }
                    else if (map[yy][xx] == 0) {
                        q.push({yy, xx, length + 1});
                        visited[yy][xx] = 1;
                        continue ;
                    }
                    else {
                        bridge_length = length;
                        found_other_land = true;
                        break ;
                    }
                }
                if (found_other_land) {
                    break;
                }
            }
            if (found_other_land) {
                min_bridge_length = min(min_bridge_length, bridge_length);
            }
        }   
    }


    return min_bridge_length;
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }   
    }

    // 대륙 구별
    // 인접하면 같은 수로 변경
    distict_land();

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << map[i][j] << ' ';
    //     }   
    //     cout << endl;
    // }

    // 대륙과 인접한 바다에서 bfs 실행하여 다리 길이 계산
    int min_bridge_length;
    min_bridge_length = bfs();
    cout << min_bridge_length << endl;

}