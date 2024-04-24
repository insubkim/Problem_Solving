#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

int N, M;
int map[1001][1001];

int find(int src, int dest, int visited[1001]) {
  // 찾음.
  if (map[src][dest] != 0) return map[src][dest];

  // 못찾음. 다른 노드 통해서 확인
  for (int i = 1; i <= N; i++) {
    if (map[src][i] == 0 || visited[i]) continue;
    
    int dist;
    visited[i] = 1;
    dist = find(i, dest, visited);
    visited[i] = 0;
    
    if (dist == 0) continue ;
    return map[src][i] + dist;
  }
  // 다른 노드 통해서도 못찾음.
  return 0;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N - 1; i++) {
    int src, dest, dist;
    cin >> src >> dest >> dist;
    map[src][dest] = dist;
    map[dest][src] = dist;
  }

  for (int i = 0; i < M; i++) {
    int src, dest, dist;
    cin >> src >> dest;

    int visited[1001] = {0, };
    visited[src] = 1;
    dist = find(src, dest, visited);
    
    cout << dist << endl;
  }
}