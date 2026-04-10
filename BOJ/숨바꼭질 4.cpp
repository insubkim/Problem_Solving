#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// 수빈이 위치, 동생 위치
int N,K;

// 이미 방문했는지 확인용
// 초기값 -1, 경로 확인용으로 방문한 노드 위치 저장
int visited[200001];


int bfs(void) {
    fill(visited, visited + 200001, -1);

    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = -2;
    
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
        if (next >= 0 && next < 200000 && visited[next] == -1) {
            q.push({next, cur.second + 1});
            visited[next] = cur.first;
        }
        next = cur.first + 1;
        if (next >= 0 && next < 200000 && visited[next] == -1) {
            q.push({next, cur.second + 1});
            visited[next] = cur.first;
        }
        next = cur.first * 2;
        if (next >= 0 && next < 200000 && visited[next] == -1) {
            q.push({next, cur.second + 1});
            visited[next] = cur.first;
        }
    }

    return -1;
}

int main() {
    cin >> N >> K;

    int min_time;
    min_time = bfs();

    cout << min_time << endl;

    // 경로 저장
    stack<int> s;
    int dest = K;
    while (visited[dest] != -2) {
        s.push(dest);
        dest = visited[dest]; 
    }
    s.push(N);
    
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}