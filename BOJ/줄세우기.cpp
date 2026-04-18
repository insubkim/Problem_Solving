#include <iostream>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <queue>

#include <string.h>

using namespace std;

int N, T;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;

    // 위상정렬 실행
    // 진입 차수가 0인 노드 위한 큐
    queue<int> q;

    // 각 노드 진입 차수 저장
    int indegree[32001] = {0, };

    // 각 노드 진출 차수 저장
    vector<int> adj[32001];

    while (T--) {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> seq;
    int visited[32001] = {0, };

    while (!q.empty()) {
        int cur = q.front();
        seq.push_back(cur);
        visited[cur] = 1;
        q.pop();

        for (auto x: adj[cur]) {
            indegree[x]--;
            if (indegree[x] == 0) {
                q.push(x);
            }
        }
    }

    for (auto x: seq) {
        cout << x << ' ';
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << i << ' ';
        }
    }

    return 0;
}