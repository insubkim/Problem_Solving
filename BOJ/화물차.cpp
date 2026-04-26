#include <iostream>
#include <tuple>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>

#include <cmath>
#include <string.h>

using namespace std;

// 세로,  가로
int m, n;

char map[21][21];

int visited[21][21];

int src[2];
int dest[2];

struct StopLight {
    char dir;
    int a;
    int b;
};

int stopLight_cnt;
struct StopLight stopLight[10];

int checkLight_ori(int dir_idx, int y, int x, int time) {
    int stopLight_num = map[y][x] - '0';
    // dir 0, 2 -
    // dir 1, 3 |

    // stopLight[stopLight_num]
    // 0 < <= a * 1
    // a * 1 < <= a * 1 + b * 1
    char start_dir = stopLight[stopLight_num].dir;
    char next_dir = start_dir == '|' ? '-' : '|';

    int a = stopLight[stopLight_num].a;
    int b = stopLight[stopLight_num].b;
    int t = 0;

    char dir = '-';
    if (dir_idx == 1 || dir_idx == 3) {
        dir = '|';
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (true) {
        // a 진입 가능
        if (t < time && time <= t + a) {
            return start_dir == dir;
        }
        t += a;
        // b 진입 가능
        if (t < time && time <= t + b) {
            return next_dir == dir;
        }
        t += b;
    }

}

int checkLight(int dir_idx, int y, int x, int time) {
    int num = map[y][x] - '0';

    char init_dir = stopLight[num].dir;
    int a = stopLight[num].a; // '-' 지속 시간
    int b = stopLight[num].b; // '|' 지속 시간

    char move_dir = '-';
    if (dir_idx == 1 || dir_idx == 3) {
        move_dir = '|';
    }

    int cycle = a + b;
    int cur = time % cycle; // 0-base로 봐야 함

    char current_dir;

    // init dir = '-'
    // a = 3 b = 7 
    // time =7 
    // cur = 0

    if (init_dir == '-') {
        // 처음에 동서
        // cur: 0 ~ a-1 => '-'
        // cur: a ~ a+b-1 => '|'
        if (cur < a) {
            current_dir = '-';
        } else {
            current_dir = '|';
        }
    } else {
        // 처음에 남북
        // cur: 0 ~ b-1 => '|'
        // cur: b ~ b+a-1 => '-'
        if (cur < b) {
            current_dir = '|';
        } else {
            current_dir = '-';
        }
    }

    return current_dir == move_dir;
}

int bfs(void) {
    deque<tuple<int, int, int>> q;
    q.push_back({src[0], src[1], 0});
    visited[src[0]][src[1]] = 1;

    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int time = get<2>(q.front());
        q.pop_front();

        if (y == dest[0] && x == dest[1]) {
            return time;
        }

        int dy[4] = {0, -1, 0, 1};
        int dx[4] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];   
            int xx = x + dx[i];   
            if (yy < 1 || yy > m) {
                continue ;
            }
            if (xx < 1 || xx > n) {
                continue ;
            }
            if (map[yy][xx] == '.') {
                continue ;
            }
            if (visited[yy][xx]) {
                continue ;
            }
            // 신호등 일때, 
            // 바로 지날수있으면 방문
            // 대기해야하면 맨앞에 insert
            if ('0' <= map[yy][xx] && map[yy][xx] <= '9' 
                && !checkLight(i, yy, xx, time)) {
                q.push_back({y, x, time + 1});
                continue ;
            }
            q.push_back({yy, xx, time + 1});
            visited[yy][xx] = 1;
        }
    }

    return -1;
}

int main(void) {
    
    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break ;
        }

        stopLight_cnt = 0;
        for (int i = 1; i <= m; i++) {
            string line;
            cin >> line;

            for (int j = 1; j <= n; j++) {
                map[i][j] = line[j - 1];
                if ('0' <= map[i][j] && map[i][j] <= '9') {
                    stopLight_cnt++;
                }
                if (map[i][j] == 'A') {
                    src[0] = i;
                    src[1] = j;
                }
                if (map[i][j] == 'B') {
                    dest[0] = i;
                    dest[1] = j;
                }
            }
        }

        for (int i = 1; i <= stopLight_cnt; i++) {
            int num;
            char dir;
            cin >> num >> dir;
            int a, b;
            cin >> a >> b;

            stopLight[num].dir = dir;
            stopLight[num].a = a;
            stopLight[num].b = b;
        }
        
        memset(visited, 0, sizeof(visited));

        int min_time;
        min_time = bfs();
        if (min_time != -1) {
            cout << min_time << '\n';
        } else {
            cout << "impossible" << '\n';
        }

    }

    return 0;
}


// 1 | 0 <  <= 3
// 1 - 3 <. <= 8
// 1 | 8 <. <= 11
// 1 - 11 < <= 16

// 2 - 0 < <= 2
// 2 | 2 < <= 6
// 2 - 6 < <=8
