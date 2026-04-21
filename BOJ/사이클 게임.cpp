#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string.h>

using namespace std;

// 정점 수, 간선 수
int V, E;

// 정점 v, 정점 u
// vector<pair<int, int>> edge;

// union-find 알고리즘 사용을 위하여 parent 선언
int parent[500001];

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

int main(void) {
    cin >> V >> E;

    init_union_find();  

    for (int i = 1; i <= E; i++) {
        int v, u;
        cin >> v >> u;

        
        int a_parent = find(v);
        int b_parent = find(u);
        
        if (a_parent == b_parent){
            cout << i << '\n';
            return 0;
        }
        unite(v, u);
    }

    cout << 0 << '\n';
}