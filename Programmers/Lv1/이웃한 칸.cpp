#include <string>
#include <vector>

using namespace std;

bool  checkRange(const vector<vector<string> >& board, int y, int x) {
  return \
    (0 <= y && y < board.size()) && 
    (0 <= x && x < board[0].size());
}

bool  isColorSame(const vector<vector<string> >& board, int y, int x, const string& target_color) {
  return \
    checkRange(board, y, x) && 
    board[y][x] == target_color;
}

int solution(vector<vector<string> > board, int h, int w) {
  string  target_color = board[h][w];
  int     count = 0;
  
  
  int   dy[4] = {-1, 0, 1, 0};
  int   dx[4] = {0, 1, 0, -1};
  for (int i = 0; i < 4; i++) {
    int y = h + dy[i];
    int x = w + dx[i];
    if (isColorSame(board, y, x, target_color)) {
      count++;
    }
  }
  return count;
}