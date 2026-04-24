#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 전체 역 수, 하나의 하이퍼 큐브가 연결하는 역 수, 하이퍼 큐브 수
int N, K, M;

vector<int> edge[100001];

vector<int> hypertube[1001];

int visited[100001];

int bfs(void) {
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1] = 1;

    while (!q.empty()) {
        int cur = q.front().first;
        int path_cnt = q.front().second;
        q.pop();

        if (cur == N) {
            return path_cnt;
        }

        for (auto &h: edge[cur]) {
            for (auto x: hypertube[h]){
                if (visited[x]) {
                    continue ;
                }    

                q.push({x, path_cnt + 1});
                visited[x] = 1;
            }
        }
    }


    return -1;
}

int main(void) {
    cin >> N >> K >> M;

    for (int i = 1; i <= M; i++) {

        // 하이퍼 큐브가 잇는 정점 번호 추가
        for (int j = 1; j <= K; j++) {
            int n;
            cin >> n;
            hypertube[i].push_back(n);
        }

        // 각 정점의 간선에는 hypercude 번호 추가
        for (auto x: hypertube[i]) {
            edge[x].push_back(i);
        }


    }

    int min_path;
    min_path = bfs();

    cout << min_path << '\n';

    return 0;
}