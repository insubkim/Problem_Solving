#include <iostream>
#include <queue>

#include <string.h>

using namespace std;

// 수빈 위치, 동생 위치
int N, K;

// 노드 방문 확인, 홀수 짝수 시간에 따라 따로 저장, 이유는 +1, -1 을 하면 해당 지점에 도착 가능.
// 따라서 나중에 동생이 수빈이가 이미 방문한 곳에 도착하더라도 방문 체크가 가능해짐.
int visited[500001][2];

int bfs(void) {
    queue<int> q;
    // 수빈 위치, 시간
    q.push(N);
    int t = 0;
    visited[N][t % 2] = 1;

    while (true) {
        int q_size = q.size();
        int k_cur = K + (t * (t + 1)) / 2;

        if (k_cur > 500000) {
            return -1;
        }

        if (visited[k_cur][t % 2]) {
            return t;
        }

        while (q_size--) {
            int x = q.front();
            q.pop();

            int dx[3] = {-1, 1, x};
            for (int i = 0; i < 3; i++) {
                int xx = x + dx[i];
         
                if (xx < 0 || xx > 500000) {
                    continue ;
                }

                if (visited[xx][(t + 1) % 2]) {
                    continue;
                }

                q.push(xx);
                visited[xx][(t + 1) % 2] = 1;
            }
        }

        t++;
    }
    return -1;
}

int main() {
    cin >> N >> K;

    int min_time;
    min_time = bfs();
    
    cout << min_time << endl;
}