#include <iostream>
#include <queue>

using namespace std;

// 도화지 세로, 가로
int n,m;

// 도화지
int map[501][501];

// 그림 수
int picture_cnt;
// 가장 큰 그림
int max_picture_area;

// 방문 표시
int visited[501][501];

int bfs(int y, int x) {
    int area = 0;
    queue<pair<int, int>> q;

    // 시작점 insert
    // 큐가 없을때 까지 반복
    // 큐 pop 
    // area ++
    // visited 처리
    // 4 빙향 방문 가능 확인
    // 방문 예정 포인트 큐 push

    q.push({y, x});
    visited[y][x] = 1;
    
    while (!q.empty()) {
        pair<int, int> coord = q.front();
        q.pop();
        area++;

        int y = coord.first;
        int x = coord.second;

        int dy[4] = {0, -1, 0, 1};
        int dx[4] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
        
            if (1 > yy || n < yy)
                continue;
            if (1 > xx || m < xx)
                continue;
        
            if (map[yy][xx] == 0)
                continue;

            if (visited[yy][xx] == 1)
                continue;

            q.push({yy, xx});
            visited[yy][xx] = 1;
        }

    }

    return area;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c;
            cin >> c;
            map[i][j] = c;
        }

    }

    // 첫 줄 첫 칸부터 자례로 bfs 실행하여 넓이 계산, 그림 수 카운트
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j]) {
                continue ;
            }

            if (map[i][j] == 0) {
                visited[i][j] = 1;
                continue;
            }

            // 방문 표시 및 넓이 계산
            int area;
            area = bfs(i, j);

            picture_cnt++;
            max_picture_area = max(max_picture_area, area);
        }
    }   

    cout << picture_cnt << endl;
    cout << max_picture_area << endl;
    return 0;
}