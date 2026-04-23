#include <iostream>
#include <tuple>
#include <algorithm>
#include <map>

#include <cmath>

using namespace std;

// 아이들 수, 친구 관계 수, 울음소리 공명 최소 아이 수
int N, M, K;

// 아이들이 가진 사탕
int child[30001];

// 아이들의 친구 포함 관계
int parent[30001];

int dp[30001][3001];

void    init_union_find(void) {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

void    unite(int a, int b) {
    int a_parent = find(a);
    int b_parent = find(b);

    if (a_parent == b_parent) return ;

    parent[b_parent] = a_parent;
}

bool    cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main(void) {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> child[i];
    }

    init_union_find();

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    // 아이들이 서로 친구 관계이면
    // 위상 정렬을 이용하여 그룹핑
    
    // 각 그룹을 총 사탕, 총 울음 소리 구조로 저장
    // vector<pair<int, int>> c;
    // 배낭 문제로 치환
    // dp[i][j] -> i 번째 그룹까지 고려하고 가방 무게가 j 일때 최대 사탕 수

    map<int, vector<int>> tmp;
    for (int i = 1; i <= N; i++) {
        int c_parent = find(i);

        if (tmp.find(c_parent) == tmp.end()) {
            vector<int> v;
            v.push_back(i);
            tmp.insert({c_parent, v});
        } else {
            tmp[c_parent].push_back(i);
        }
    }

    vector<pair<int, int>> c;
    for (auto &x : tmp) {
        int total_candy = 0;
        int total_child = 0;
        for (auto &y : x.second) {
            total_candy += child[y];
            total_child++;
        }
        c.push_back({total_child, total_candy});
    }

    sort(c.begin(), c.end(), cmp);

    for (int i = 1; i <= c.size(); i++) {
        for (int j = 1; j < K; j++) {
            int w = c[i - 1].first;
            int v = c[i - 1].second;
            if (j < w) {
                dp[i][j] = dp[i - 1][j];
                continue ;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
        }
    }

    cout << dp[c.size()][K - 1] << '\n';

    return 0;
}