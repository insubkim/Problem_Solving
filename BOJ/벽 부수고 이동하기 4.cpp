#include <iostream>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <set>
#include <queue>

#include <string.h>

using namespace std;

int N,M;

int id = 1;

int board[1001][1001];
int board_id[1001][1001];

int visited[1001][1001];

void    bfs(int y, int x) {
    if (visited[y][x]) {
        return ;
    }
    
    queue<pair<int, int>> q;
    vector<pair<int,int>> cells;
    q.push({y, x});
    visited[y][x] = 1;
    cells.push_back({y, x});

    int total_visit = 1;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();


        int dy[4] = {0, -1, 0, 1};
        int dx[4] = {-1, 0, +1, 0};
        for (int i = 0; i < 4; i++) {
            int yy = dy[i] + y;
            int xx = dx[i] + x;
            if (yy < 1 || yy > N) {
                continue ;
            }
            if (xx < 1 || xx > M) {
                continue ;
            }
            if (visited[yy][xx]) {
                continue ;
            }
            if (board[yy][xx] != 0) {
                continue;
            }
            q.push({yy, xx});
            visited[yy][xx] = 1;
            cells.push_back({yy, xx});
            total_visit++;
        }
    }

    for (auto &c: cells) {
        int y = c.first;
        int x = c.second;
        
        board[y][x] = total_visit;
        board_id[y][x] = id;
    }
    id++;
}


void    solve(void) {
    // 0 인 칸에서 bfs 실행 
    // 이후 모든 방문 칸을 방문 가능한 칸수로 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] == 0) {
                bfs(i, j);
            }
        }   
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++) {
            board[i][j] = line[j - 1] - '0';
            if (board[i][j] == 1) {
                board[i][j] = -1;
            }
        }   
    }

    solve();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // cout << board[i][j] << ' ';
            if (board[i][j] == -1) {
                int dy[4] = {0, -1, 0, 1};
                int dx[4] = {-1, 0, +1, 0};
                int s = 0;
                set<int> ids;
                
                for (int k = 0; k < 4; k++) {
                    int yy = dy[k] + i;
                    int xx = dx[k] + j;
                    if (yy < 1 || yy > N) {
                        continue ;
                    }
                    if (xx < 1 || xx > M) {
                        continue ;
                    }
                    if (board[yy][xx] == -1) {
                        continue ;
                    }
                    if (ids.find(board_id[yy][xx]) != ids.end()) {
                        continue ;
                    }
                    ids.insert(board_id[yy][xx]);
                    s += board[yy][xx];
                }
                cout << (s + 1) % 10;
            } else {
                cout << '0';
            }
        }   
        cout << '\n';
    }

    return 0;
}