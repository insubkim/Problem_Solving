#include <iostream>
#include <queue>

using namespace std;

// 수빈이 위치, 동생 위치
int N,K;

// 이미 방문했는지 확인용
bool visited[200001];

int bfs(void) {
    queue<pair<int, int>> q;
    q.push({N, 0});

    while (!q.empty()) {
        pair<int, int> cur;
        cur = q.front();
        q.pop();
        
        if (cur.first == K) {
            return cur.second;
        }

        // 이동
        // -1, +1, 혹은 현재 *2
        int next;

        next = cur.first - 1;
        if (next >= 0 && next < 200000 && !visited[next]) {
            q.push({next, cur.second + 1});
            visited[next] = true;
        }
        next = cur.first + 1;
        if (next >= 0 && next < 200000 && !visited[next]) {
            q.push({next, cur.second + 1});
            visited[next] = true;
        }
        next = cur.first * 2;
        if (next >= 0 && next < 200000 && !visited[next]) {
            q.push({next, cur.second + 1});
            visited[next] = true;
        }
    }

    return -1;
}

int main() {
    cin >> N >> K;

    int min_time;
    min_time = bfs();

    cout << min_time << endl;
}