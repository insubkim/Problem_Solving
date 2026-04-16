#include <iostream>
#include <queue>

#include <string.h>

using namespace std;

// 수빈이 위치, 동생 위치
int N,K;

// 이미 방문했는지 확인용
bool visited[200001];
bool temp_visited[200001];


int min_time;
int min_time_case;

void bfs(void) {
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = 1;

    while (!q.empty()) {
        int q_size = q.size();
        memcpy(temp_visited, visited, sizeof(visited));

        while (q_size--) {
            pair<int, int> cur;
            cur = q.front();
            q.pop();
            
            if (cur.first == K) {
                min_time = cur.second;
                min_time_case++;
            }

            // 이동
            // -1, +1, 혹은 현재 *2
            int next;

            next = cur.first - 1;
            if (next >= 0 && next < 200000 && !visited[next]) {
                q.push({next, cur.second + 1});
                temp_visited[next] = true;
            }
            next = cur.first + 1;
            if (next >= 0 && next < 200000 && !visited[next]) {
                q.push({next, cur.second + 1});
                temp_visited[next] = true;
            }
            next = cur.first * 2;
            if (next >= 0 && next < 200000 && !visited[next]) {
                q.push({next, cur.second + 1});
                temp_visited[next] = true;
            }
        }

        if (min_time_case) {
            return ;
        }

        memcpy(visited, temp_visited, sizeof(visited));
    }
}

int main() {
    cin >> N >> K;

    bfs();

    cout << min_time << endl;
    cout << min_time_case << endl;
}