#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

int T;

int N, K;
int delay[1001];
int dep[1001];
vector<int> adj[1001];
int w;

void  solve() {
  queue<int> q;
  int result[1001] = {0, };
  for (int i = 1; i <= N; i++) {
    if (dep[i] == 0) q.push(i);

    result[i] = delay[i];
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == w) break ;
    for (size_t i = 0; i < adj[cur].size(); i++) {
      int next = adj[cur][i];
      dep[next]--;
      result[next] = max(result[next], result[cur] + delay[next]);
    
      if (dep[next] == 0) q.push(next);
    }
  }

  cout << result[w] << endl;
}

int main() {
  cin >> T;

  while (T--) {
    cin >> N >> K;
    
    memset(delay, 0, sizeof(delay));
    for (int i = 1; i <= N; i++) {
      cin >> delay[i];
    }

    for(int i = 1; i <= N; i++) {
      adj[i].clear();
    }
    memset(dep, 0, sizeof(dep));
    for (int i = 1; i <= K; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      dep[y]++;
    }
    
    cin >> w;

    solve();
  } 
}