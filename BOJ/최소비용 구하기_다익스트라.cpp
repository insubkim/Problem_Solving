#include <iostream>
#include <stack>
#include <tuple>
#include <string>
#include <map>
#include <vector>
#include <queue>

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

// 도착지까지의 거리 저장
int d[1001];

void    dijkstra(void) {
    // 다익스트라 알고리즘 위해 최소 우선순위 큐 선언
    // 거리, 노드 저장
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    // 시작점은 거리 0
    d[src] = 0;

    // 시작점 우선순위 큐에 추가
    q.push({0, src});

    while (!q.empty()) {
        int cur_dist = q.top().first;
        int cur = q.top().second;
        q.pop();


        // 이전에 더 짧은 경로 찾았으면 무시
        if (d[cur] < cur_dist) {
            continue ;
        }

        // 인접 노드 방문
        for (auto &x: edge[cur]) {
            // 다음 인접 노드 (인접 노드의 인접 노드)
            int next_node = x.first;
            // 인접 노드까지의 거리
            int next_dist = x.second;

            // "시작 -> ... -> 현재 노드 -> 인접 노드" 경로가 더 짧으면 거리 테이블 갱신 
            if (d[next_node] > cur_dist + next_dist) {
                d[next_node] = cur_dist + next_dist;
                q.push({d[next_node], next_node});
            }
        }
    
    }

}

int main(void) {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int src, dest, distance;
        cin >> src >> dest >> distance;
        
        edge[src].push_back({dest, distance});
    }

    fill(d, d + 1001, 2147483647);

    cin >> src >> dest;

    dijkstra();
    cout << d[dest] << '\n';

}