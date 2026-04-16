#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> edge(100001);
int parent[100001] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    // 부모 찾기
    // 1 자식들의 부모는 전부 1
    // 위에서 찾은 자식들의 모든 자식의 부모는 전부 본인
    // 반복

    // 현 노드 번호, 부모 노드 번호 
    queue<pair<int, int>> q;
    for (auto x: edge[1]) {
        parent[x] = 1;
        q.push({x, 1});
    }


    while (!q.empty()) {
        int v = q.front().first;
        int p = q.front().second;
        q.pop();

        for (auto x: edge[v]) {
            if (x == p) {
                continue ;
            }
            parent[x] = v;
            q.push({x, v});
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}