#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#include <vector>

#include <cmath>

using namespace std;

int N;

int build_time[501];

int indegree[501];

vector<int> adj[501];

int result[501];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int time;
        cin >> time;
        build_time[i] = time;
        
        while (true) {
            int dep;
            cin >> dep;
            if (dep == -1) {
                break ;
            }
            adj[dep].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            result[i] = build_time[i];
        }
    }

    while (!q.empty()) {
        int node;
        node = q.front();
        q.pop();

        for (int x : adj[node]) {
            indegree[x]--;
            result[x] = max(result[x], result[node] + build_time[x]);
            
            if (indegree[x] == 0) {
                q.push(x);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << '\n';
    }


    return 0;
}