#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int get_min_paint(int row, int col, char board[][50]) {
  int   first_black_cnt = 0;
  int   first_white_cnt = 0;

  for (int i = row; i < row + 8; i++) {
    char first_black = i % 2 ? 'B' : 'W';
    char first_white = i % 2 ? 'W' : 'B';
    for (int j = col; j < col + 8; j++) {
      if (board[i][j] != first_black) first_black_cnt++;
      if (board[i][j] != first_white) first_white_cnt++;
      first_black = first_black == 'B' ? 'W' : 'B';
      first_white = first_white == 'B' ? 'W' : 'B';
    }
  }
  return min(first_black_cnt, first_white_cnt);
}

int main() {
  int width, height;

  cin >> height >> width;
  char board[50][50];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> board[i][j];
    }
  }
  int min_cnt = INT_MAX;
  for (int i = 0; i <= height - 8; i++) {
    for (int j = 0; j <= width - 8; j++) {
      min_cnt = min(get_min_paint(i, j, board), min_cnt);
    } 
  }
  cout << min_cnt << endl;
}