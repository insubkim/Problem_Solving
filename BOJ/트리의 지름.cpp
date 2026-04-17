#include <iostream>
#include <stack>
#include <tuple>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

// 정점 수
int V;

// 벡터의 인덱스는 정점, map 은 연결된 다른 정점과의 거리
vector<pair<int, int>> edge[100001];

int visited[100001];

int max_dist;
int endpoint;

void    dfs(int cur, int total_dist) {
    if (max_dist < total_dist) {
        max_dist = total_dist;
        endpoint = cur;
    }

    for (auto &x: edge[cur]) {
        int next_node = x.first;
        int dist = x.second;
        
        if (visited[next_node]) {
            continue ;
        }
        visited[next_node] = 1;
        dfs(next_node, total_dist + dist);
        visited[next_node] = 0;
    }
}

int main(void) {
    cin >> V;
    for (int i = 1; i <= V; i++) {
        int src, dest, dist;
        cin >> src;
        while (true) {
            cin >> dest;
            if (dest == -1) {
                break ;
            }
            cin >> dist;
            edge[src].push_back({dest, dist});
        }
    }
    
    // 1. 끝점 하나 찾기
    // 노드 1에서 가장 긴 경로 확인
    // 2. 찾은 끝점 부터 가장 긴 경로 확인

    visited[1] = 1;
    dfs(1, 0);

    memset(visited, 0, sizeof(visited));
    visited[endpoint] = 1;
    dfs(endpoint, 0);
    cout << max_dist << endl;

    return 0;
}