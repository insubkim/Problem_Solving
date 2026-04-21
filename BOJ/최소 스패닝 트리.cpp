#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string.h>

using namespace std;

// 정점 수, 간선 수
int V, E;

// 정점 v, 정점 u, 가중치
vector<tuple<int, int, int>> edge;

// union-find 알고리즘 사용을 위하여 parent 선언
int parent[10001];

void    init_union_find(void) {
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x) return x;
    // 최적화
    // 한번 parent 를 찾고난뒤, 전부 root parent로 바꿔준다.
    return parent[x] = find(parent[x]);
}

void    unite(int a, int b) {
    int a_parent = find(a);
    int b_parent = find(b);

    if (a_parent == b_parent) return ;

    parent[b_parent] = a_parent;
}

bool    cmp(tuple<int, int, int> &a, tuple<int, int, int> &b) {
    return get<2>(a) < get<2>(b);
}

long long kruskal(void) {
    long long min_spanning = 0;

    // 가중치 중 가장 작은 값 선택
    // 사이클 확인
    // 모든 정점 선택 완료시까지 진행
    int edge_idx = 0;

    for (int i = 1; i <= V - 1; i++) {
        while (true) {
            if (edge_idx == edge.size())
                return -1;
        
            tuple<int, int, int> &t = edge[edge_idx];
            edge_idx++;
            
            int v = get<0>(t);
            int u = get<1>(t);
            int w = get<2>(t);
            int v_parent = find(v);
            int u_parent = find(u);
            if (v_parent != u_parent) {
                unite(v, u);
                min_spanning += w;
                break ;
            }

        }

    }

    return min_spanning;
}

int main(void) {
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int v, u, w;
        cin >> v >> u >> w;

        edge.push_back({v, u, w});
    }

    sort(edge.begin(), edge.end(), cmp);
     
    init_union_find();

    // kruskal
    long long min_spanning;
    min_spanning = kruskal();

    cout << min_spanning << '\n';
}