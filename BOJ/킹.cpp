#include <iostream>
#include <cmath>
#include <string>
#include <assert.h>

using namespace std;

int king[2];
int rock[2];

bool  check_map_range(int x, int y) {
  return 0 <= x && x < 8 \
    &&  0 <= y && y < 8;  
}

/*
    R : 한 칸 오른쪽으로
    L : 한 칸 왼쪽으로
    B : 한 칸 아래로
    T : 한 칸 위로
    RT : 오른쪽 위 대각선으로
    LT : 왼쪽 위 대각선으로
    RB : 오른쪽 아래 대각선으로
    LB : 왼쪽 아래 대각선으로
 */
void  try_move(int* x, int* y, string mv) {
  if (mv.find('R') != string::npos) ++*x;
  if (mv.find('L') != string::npos) --*x;
  if (mv.find('B') != string::npos) ++*y;
  if (mv.find('T') != string::npos) --*y;
  assert(-1 <= *x && *x <= 8);
  assert(-1 <= *y && *y <= 8);
}

void  input(int in[2]) {
  // 1 -> 7 | a -> 0
  // 2 -> 6 | b -> 1
  // ..     | ..
  // 8 -> 0 | h -> 7
  char x,y;
  cin >> x >> y;
  in[0] = x - 'A';
  in[1] = 8 - (y - '0');
  assert(0 <= in[0] && in[0] <= 7);
  assert(0 <= in[1] && in[1] <= 7);
}

int main() {
  input(king);
  input(rock);

  int t;
  cin >> t;
  while (t--) {
    string mv;
    cin >> mv;
    int x = king[0];
    int y = king[1];
    //move
    try_move(&x, &y, mv);
    if (!check_map_range(x, y)) 
      continue;
    if (x == rock[0] && y == rock[1]) {
      int xx = rock[0];
      int yy = rock[1];
      try_move(&xx, &yy, mv);
      if (!check_map_range(xx, yy))
        continue;
      king[0] = x;
      king[1] = y;
      rock[0] = xx;
      rock[1] = yy;
      assert(x != xx || y != yy);
    } else {
      king[0] = x;
      king[1] = y;
    }
    assert(king[0] != rock[0] || king[1] != rock[1]);
  }

  cout << (char)(king[0] + 'A') << 8 - king[1] << "\n";
  cout << (char)(rock[0] + 'A') << 8 - rock[1] << "\n";
}