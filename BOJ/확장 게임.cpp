#include <iostream>
#include <queue>
#include <tuple>
#include <string>

#include <string.h>

using namespace std;

// 세로 가로
int N,M;

// 플레이어 수
int P;

// 플레이어별 움직일수있는 칸 수
int move_cnt[10];

char map[1001][1001];

queue<pair<int, int>> q[10];

void    bfs(void) {
    // 1 ~ p 번까지 순서대로 확장
    // 확장시 모든 경계 값이 동시 확장(frontier) 시도
    // 움직일수있는 칸수는 최대 move_cnt[p]
    
    bool frontiered = true;
    while (frontiered) {
        frontiered = false;
        
        // 플레이어 순서대로 시작
        for (int p = 1; p <= P; p++) {
            int max_move_cnt = move_cnt[p];

            // 대기 큐에서 한칸식 max칸 만큼 확장 시도
            for (int i = 1; i <= max_move_cnt; i++) {
                int q_size = q[p].size();

                if (q_size == 0) {
                   break;
                }
                
                while (q_size--) {
                    int y = q[p].front().first;
                    int x = q[p].front().second;
                    q[p].pop();

                    int dy[4] = {0, -1, 0, +1};
                    int dx[4] = {-1, 0, +1, 0};
                    for (int i = 0; i < 4; i++) {
                        int yy = y + dy[i];
                        int xx = x + dx[i];
                        if (yy < 1 || yy > N) {
                            continue ;
                        }
                        if (xx < 1 || xx > M) {
                            continue ;
                        }
                        if (map[yy][xx] != '.') {
                            continue ;
                        }
                        map[yy][xx] = '0' + p;
                        q[p].push({yy, xx});
                        frontiered = true;
                    }


                }
            }
        }


    }

}

int main() {
    cin >> N >> M >> P;

    for (int i = 1; i <= P; i++) {
        cin >> move_cnt[i];
    }

    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++) {
            map[i][j] = line[j - 1];
            if ('0' < map[i][j] && map[i][j] <= '9') {
                int p = map[i][j] - '0';
                q[p].push({i, j});
            }
        }
    }

    bfs();

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << map[i][j];
    //     }
    //     cout << '\n';
    // }

    int ans[10] = {0, };
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans[map[i][j] - '0']++;
        }
    }
    for (int i = 1; i <= P; i++) {
        cout << ans[i] << endl;
    }
}