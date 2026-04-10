#include <iostream>
#include <deque>

#include <string.h>

using namespace std;

// 수빈 위치, 동생 위치
int N, K;

int dist[200001];

int _0_1_bfs(void) {
    fill(dist, dist + 200001, 2147383647);

    deque<pair<int, int>> dq;
    dq.push_back({N, 0});
    dist[N] = 0;
    if (N == K) {
        return 0;
    }

    while (!dq.empty()) {
        int x = dq.front().first;
        int t = dq.front().second;
        dq.pop_front();
        
        for (int xx = x + x; xx <= 200000 && xx; xx *= 2) {
            if (t < dist[xx]) {
                dist[xx] = t;
                dq.push_front({xx, t});            
            }
        }

        int dx[2] = {-1, 1};
        for (int i = 0; i < 2; i++) {
            int xx = x + dx[i];
            
            if (xx < 0 || xx > 200000) {
                continue ;
            }

            if (t + 1 < dist[xx]) {
                dist[xx] = t + 1;
                dq.push_back({xx, t + 1});
            }
        }
    }

    return dist[K];
}

int main() {
    cin >> N >> K;

    int min_time;
    min_time = _0_1_bfs();

    cout << min_time << endl;
}