#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <array>

#include <string.h>

using namespace std;

// 세로, 가로
int R,C;

char map[21][21];

int max_move;

bool used_alpha[26] = {0, };

int bfs(void) {
    // 1, 1 부터 시작하여 bfs 실행
    // 이때까지 지난 알파벳 저장
    int max_move = 0;

    queue<tuple<int, int, array<bool, 26>>>q;
    array<bool, 26> alpha = {false, };
    alpha[map[1][1] - 'A'] = true;
    q.push({1, 1, alpha});

    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        array<bool, 26> alpha = get<2>(q.front());
        q.pop();

        int move = 0;
        for (auto x: alpha) {
            if (x) {
                move++;
            }
        }
        max_move = max(max_move, move);

        int dy[4] = {0, -1, 0, +1};
        int dx[4] = {-1, 0, +1, 0};
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            array<bool, 26> new_alpha = alpha; 
            if (yy < 1 || yy > R) {
                continue ;
            }
            if (xx < 1 || xx > C) {
                continue ;
            }
            if (alpha[map[yy][xx] - 'A']) {
                continue ;
            }
            new_alpha[map[yy][xx] - 'A'] = true;
            q.push({yy, xx, new_alpha});
        }
    
    }
    return max_move;
}

void    dfs (int y, int x, int dist) {
    max_move = max(max_move, dist);


    int dy[4] = {0, -1, 0, +1};
    int dx[4] = {-1, 0, +1, 0};
    for (int i = 0; i < 4; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (yy < 1 || yy > R) {
                continue ;
        }
        if (xx < 1 || xx > C) {
            continue ;
        }
        if (used_alpha[map[yy][xx] - 'A']) {
            continue ;
        }
        used_alpha[map[yy][xx] - 'A'] = true;
        dfs(yy, xx, dist + 1);
        used_alpha[map[yy][xx] - 'A'] = false;
    }

}

int main() {
    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= C; j++) {
            map[i][j] = line[j - 1];
        }
    }

    used_alpha[map[1][1] - 'A'] = true;
    dfs(1, 1, 1);
    cout << max_move << endl;
}