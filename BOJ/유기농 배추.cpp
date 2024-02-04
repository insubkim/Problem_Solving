#include <iostream>

using namespace std;

int width, length, cabages;
int map[50][50];

bool  in_range(int y, int x) {
  return (0 <= y && y < length) \
    &&  (0 <= x && x < width);
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void  set_worm(int y, int x) {
  map[y][x] = 2;
  for (int i = 0; i < 4; i++) {
    int xx = dx[i] + x;
    int yy = dy[i] + y;
    if (in_range(yy, xx) && map[yy][xx] == 1) {
      set_worm(yy, xx);
    }
  }
}

void  solve() {
  int cnt = 0;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      if (map[i][j] == 1) {
        cnt++;
        set_worm(i, j);
      }
    } 
  }
  cout << cnt << endl;
}

int main () {
  int T;
  cin >> T;
  while (T--) {
    memset(map, 0, sizeof map);
    cin >> width >> length >> cabages;
    for (int i = 0; i < cabages; i++) {
      int x,y;
      cin >> x >> y;
      map[y][x] = 1;
    }
    solve();
  }
}