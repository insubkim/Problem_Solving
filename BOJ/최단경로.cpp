#include <iostream>
#include <queue>
#include <vector>

#include <string.h>

using namespace std;

// 정점 수, 간선 수
int V, E;
// 시작 노드
int start_node;

vector<pair<int, int>> edge[20001];

int d[20001];

void    dijkstra(void) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    q.push({0, start_node});

    while (!q.empty()) {
        int total_dist = q.top().first;
        int cur = q.top().second;
        q.pop();
        
        if (d[cur] < total_dist) {
            continue ;
        }

        for (auto &x : edge[cur]) {
            int next = x.first;
            int next_dist = x.second;
        
            if (d[next] > total_dist + next_dist) {
                q.push({total_dist + next_dist, next});
                d[next] = total_dist + next_dist;
            }
        }
    
    }
}

int main(void) {
    cin >> V >> E >> start_node;

    for (int i = 1; i <= E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }

    fill(d, d + 20001, 1e9);
    d[start_node] = 0;

    dijkstra();

    for (int i = 1; i <= V; i++) {
        if (d[i] == 1e9) {
            cout << "INF" << '\n';
        } else {
            cout << d[i] << '\n';
        }
    }

    return 0;
}