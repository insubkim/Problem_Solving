#include <iostream>
#include <cmath>

using namespace std;

int N, M;

bool  is_square(int y, int x, int dist, int map[][50]) {
  return x + dist < M && y + dist < N \
      && map[y][x] == map[y][x + dist] \
      && map[y][x + dist] == map[y + dist][x] \
      && map[y + dist][x] == map[y + dist][x + dist];
}

int main() {
  cin >> N >> M;
  int map[50][50];
  for (int i = 0 ; i < N; i++) {
    for (int j = 0 ; j < M; j++) {
      char c;
      cin >> c;
      map[i][j] = c - '0';
    }  
  }
  int max_sqr = 1;
  for (int i = 0 ; i < N; i++) {
    for (int j = 0 ; j < M; j++) {
      for (int k = j + 1 ; k < M; k++) {
        if (is_square(i, j, k - j, map)){
          max_sqr = max(max_sqr, (int)pow(k - j + 1, 2));
        } 
      } 
    }  
  } 
  cout << max_sqr << endl;
}