#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int row, col;
int A[50][50];
int B[50][50];
int cnt = -1;

bool  isSame(int A[][50]) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (A[i][j] != B[i][j]) return false;
    }
  }
  return true;
}

void  solve(int C[][50], int r, int c, int move_cnt) {
  if (isSame(C)) {
    cnt = cnt == -1 ? move_cnt : min(cnt, move_cnt);
    return ;
  }
  if (r > row - 3 || c > col - 3)
    return ;
  int D[50][50];
  memcpy(D, C, 50 * 50);
  int next_c = (c + 1) > col - 3 ? 0 : c + 1;
  int next_r = next_c == 0 ? r + 1 : r;
  //no move
  solve(D, next_r, next_c, move_cnt);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      D[i + r][j + c] = !D[i + r][j + c];
    }
  }
  //move
  solve(D, next_r, next_c, move_cnt + 1);
}

int main() {
  cin >> row >> col;
  for (int i = 0; i < row; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < col; j++) {
      A[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < row; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < col; j++) {
      B[i][j] = s[j] - '0';
    }
  }
  
  solve(A, 0, 0, 0);
  cout << cnt << endl;
}