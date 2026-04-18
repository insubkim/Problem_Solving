#include <iostream>
#include <stack>
#include <tuple>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

#include <string.h>

using namespace std;

// 문제 수, 정보 수
int N, M;

// 진입 차수
int degree[32001];

// 인접 배열
vector<int> adj[32001];

int main(void) {
    cin >> N >> M;

    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        degree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.top();
        q.pop();

        cout << cur << ' ';
        
        for (auto x: adj[cur]) {
            degree[x]--;
            if (degree[x] == 0) {
                q.push(x);
            }
        }
    }
    cout << '\n';
    
    return 0;
}