#include <iostream>
#include <string>
#include <queue>
#include <tuple>

#include <string.h>

using namespace std;

// 테스트 케이스
int N;

// 체스판 크기
int L;

// 초기 말 위치
int coord[2];

// 도달 위치
int dest[2];

int visited[301][301];

int bfs(void) {
    memset(visited, 0, sizeof(visited));
    
    queue<tuple<int, int, int>> q;
    q.push({coord[0], coord[1], 0});
    visited[coord[0]][coord[1]] = true;
    if (coord[0] == dest[0] && coord[1] == dest[1])
        return 0;

    while (!q.empty()) {
        int y = std::get<0>(q.front());
        int x = std::get<1>(q.front());
        int time = std::get<2>(q.front());
        q.pop();

        int dy[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
        int dx[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
        for (int i = 0; i < 8; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (yy < 0 || yy >= L) {
                continue ;
            }
            if (xx < 0 || xx >= L) {
                continue ;
            }
            if (visited[yy][xx]) {
                continue ;
            }
            q.push({yy, xx, time + 1});
            visited[yy][xx] = true;
            if (yy == dest[0] && xx == dest[1]) {
                return time + 1;
            }
        }

    }
    
    return -1;
}

int main() {
    cin >> N;

    while (N--) {
        cin >> L;
        cin >> coord[0] >> coord[1];
        cin >> dest[0] >> dest[1];
        
        int min_time;
        min_time = bfs();
        cout << min_time << endl;
    }

    return 0;   
}