#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int row, col;
int A[50][50];
int B[50][50];
int cnt;

bool  isSame(void) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (A[i][j] != B[i][j]) return false;
    }
  }
  return true;
}

void  move(int row, int col) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A[i + row][j + col] &= 1;
    }  
  }
}

void  solve(void) {
  cnt = 0;
  for (int i = 0; i < row - 2; i++) {
    for (int j = 0; j < col - 2; j++) {
      if (A[i][j] == B[i][j]) continue;
      move(i, j);
      cnt++;
    }
  }
  if (!isSame()) cnt = -1;
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
  solve();
  cout << cnt << endl;
}