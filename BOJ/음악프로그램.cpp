#include <iostream>
#include <stack>
#include <tuple>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

#include <string.h>

using namespace std;

// 가수 수, pd 수 
int N, M;

int indegree[1001];

vector<int> adj[1001];

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cin.ignore();
    while (M--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int x;
        int prev = -1;
        int cnt;
        ss >> cnt;
        while (cnt--) {
            ss >> x;
            if (prev == - 1) {
                prev = x;
                continue ;
            }
            adj[prev].push_back(x);
            indegree[x]++;
            prev = x;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    queue<int> seq;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        seq.push(cur);

        for (auto &x : adj[cur]) {
            indegree[x]--;
            if (indegree[x] == 0) {
                q.push(x);
            }
        }

    }

    if (seq.size() == N) {
        while (!seq.empty()) {
            cout << seq.front() << '\n';
            seq.pop();
        }
    } else {
        cout << "0" << '\n';
    }
    return 0;
}