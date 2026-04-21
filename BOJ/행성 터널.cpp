#include <iostream>
#include <tuple>
#include <algorithm>

#include <cmath>

using namespace std;

int N;

// 정점
vector<tuple<int, int, int>> p;

vector<tuple<int, int, int>> edge;

int parent[100001];

void    init_union_find(void) {
    for (int i = 0; i < N; i++) {
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

int main(void) {
    cin >> N;

    vector<pair<int, int>> vx;
    vector<pair<int, int>> vy;
    vector<pair<int, int>> vz;

    for (int i = 0; i < N; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        p.push_back({x, y, z});
        
        vx.push_back({x, i});
        vy.push_back({y, i});
        vz.push_back({z, i});
    }

    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    sort(vz.begin(), vz.end());

    for (int i = 0; i < N - 1; i++) {
        edge.push_back({vx[i].second, vx[i + 1].second, abs(vx[i].first - vx[i + 1].first)});
        edge.push_back({vy[i].second, vy[i + 1].second, abs(vy[i].first - vy[i + 1].first)});
        edge.push_back({vz[i].second, vz[i + 1].second, abs(vz[i].first - vz[i + 1].first)});
    }

    // mst
    sort(edge.begin(), edge.end(), cmp);

    init_union_find();

    
    for (int i = 0; i < N; i++) {
        edge.push_back({vx[i].second, vx[i + 1].second, abs(vx[i].first - vx[i + 1].first)});
        edge.push_back({vy[i].second, vy[i + 1].second, abs(vy[i].first - vy[i + 1].first)});
        edge.push_back({vz[i].second, vz[i + 1].second, abs(vz[i].first - vz[i + 1].first)});
    }
    
    unsigned long long min_dist = 0;
    int edge_idx = 0;    
    for (int i = 0; i < N - 1; i++) {
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
                min_dist += w;
                break ;
            }
        }
    }

    cout << min_dist << '\n';

    return 0;
}