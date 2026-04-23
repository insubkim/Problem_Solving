#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 도시 수, 버스 수
int n, m;

// dest, 비용
vector<pair<int, int>> bus[100001];

// 출발지와 도착지
int start_node;
int end_node;

int dist[100001];

// 다익스트라 최단거리 알고리즘을 실행하고 더 짧은 간선을 발견했을때
// prev_node[dest] 에는 이전 노드인 src 노드 저장
int prev_node[100001];

void    dijkstra(void) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, start_node});
    dist[start_node] = 0;
    prev_node[start_node] = -1;

    while (!q.empty()) {
        int total_dist = q.top().first;
        int cur = q.top().second;
        q.pop();

        if (dist[cur] < total_dist) {
            continue ;
        }

        for (auto &x: bus[cur]) {
            int next = x.first;
            int cost = x.second;
            
            if (dist[next] > total_dist + cost) {
                q.push({total_dist + cost, next});
                dist[next] = total_dist + cost;
                prev_node[next] = cur;
            }
        }
    }

}

int main(void) {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int src, dest, cost;
        cin >> src >> dest >> cost;
        bus[src].push_back({dest, cost});
    }

    cin >> start_node >> end_node;

    fill(dist, dist + 100001, 2147483647);
    dijkstra();

    cout << dist[end_node] << endl;
    
    int prev = end_node;
    vector<int> route;
    while (prev != -1) {
        route.push_back(prev);
        prev = prev_node[prev];
    }
    reverse(route.begin(), route.end());
    
    cout << route.size() << '\n';
    
    for (auto x: route) {
        cout << x << ' ';
    }

    return 0;
}