#include <iostream>
#include <cassert>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;//가로 세로
char arr[100][100];
int mine, enemy;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void  cal_power(int row, int col, char color, int *sum) {
  if (arr[row][col] == 0) return ;
  
  ++*sum;

  arr[row][col] = 0;
  for (int i = 0; i < 4; i++) {
    int y = row + dy[i];
    int x = col + dx[i];
    if (y < 0 || y >= M || x < 0 || x >= N || color != arr[y][x]) continue ;
    cal_power(y, x, color, sum);
  }
}

void  solve() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      int tmp = 0;
      char color = arr[i][j];
      cal_power(i, j, arr[i][j], &tmp);
      if (color == 'W')  mine += pow(tmp, 2);
      if (color == 'B') enemy += pow(tmp, 2);
    } 
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    } 
  }
 
  solve();

  cout << mine << " " << enemy << endl;
}