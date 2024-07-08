#include <iostream>
#include <cassert>
#include <cmath>
#include <string>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int trust[100001][100001];
  memset(trust, 0, sizeof(trust));

  for (int i = 1; i <= M; i++) {
    int src, dest;
    cin >> src >> dest;
    trust[src][dest] = 1;
  }
  

  for (int i = 1; i <= M; i++) {
    int visited[100001] = {0, };
    bfs(i, visited);
  }


}