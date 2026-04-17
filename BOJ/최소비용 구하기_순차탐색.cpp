#include <iostream>
#include <stack>
#include <tuple>
#include <string>
#include <map>
#include <vector>

#include <string.h>

using namespace std;

// 도시 수 (노드)
int N;

// 버스 수 (간선 수)
int M;

// 간선 인덱스는 시작점, <도착, 가는 비용>
vector<pair<int, int>> edge[1001];

// 시작점, 도착점
int src, dest;

int visited[1001];

int min_dist = 2147483647;

void    dfs(int cur, int total_dist) {
    if (cur == dest) {
        min_dist = min(min_dist, total_dist);
        return ;
    }

    // 간선 방문
    // 간선 확인 후 큐에 추가
    for (auto &x: edge[cur]) {
        int new_cur = x.first;
        int new_dist = x.second;

        if (visited[new_cur]) {
            continue ;
        }
        visited[new_cur] = 1;
        dfs(new_cur, total_dist + new_dist);
        visited[new_cur] = 0;
    }
    
}

int main(void) {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int src, dest, distance;
        cin >> src >> dest >> distance;
        
        edge[src].push_back({dest, distance});
        // edge[dest].push_back({src, distance});
    }

    cin >> src >> dest;

    visited[src] = 1;
    dfs(src, 0);
    cout << min_dist << '\n';

}