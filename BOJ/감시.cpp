#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int m = -1;
int width, height;
int space;

void  paint_line(array<array<int, 8>, 8> map, int y, int x, int dir, int type) {
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  //01234 ->
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      map[y][x] = 100;
      y += dy[dir];
      x += dx[dir];
    } 
  }
  dir = (dir + 2) % 4;
  //134 <-

  dir = (dir - 1) % 4;
  //234 up

  dir = (dir + 3) % 4;
  //4 down

  switch (dir)
  {
  case 4

  case 3
  case 2
  case 1
  case 0
  
  default:
    break;
  }

}

int get_space(array<array<int, 8>, 8> map, vector<array<int, 3> > cctv) {
  for (int i = 0; i < cctv.size(); i++) {
    int y = cctv[i][0];
    int x = cctv[i][1];
    int dir = cctv[i][2];

    switch (map[y][x])
    {
    case 0 //한줄
      paint_line(map, y, x, dir, 0);
      break;
    case 1 //두줄
      paint_line(map, y, x, dir, 1);
      break;
    case 2 //두줄
      paint_line(map, y, x, dir, 2);
      break;
    case 3 //세줄
      paint_line(map, y, x, dir, 3);
      break;
    case 4 //네줄
      paint_line(map, y, x, dir, 4);
      break;
    default:
      assert(0);      
      break;
    }
  }
  int space = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (map[i][j] == 0) space++;
    } 
  }
  return space;
}

void  solve(array<array<int, 8>, 8>& map, vector<array<int, 3> > cctv, int cnt) {
  if (cnt == cctv.size()) {
    int tmp = get_space(map, cctv);
    space = min(space, tmp);
    return ;
  }
  for (int i = 0; i < 4; i++) {
    solve(map, cctv, cnt + 1);
    cctv[cnt][2]++;
  }
}


int main() {
  array<array<int, 8>, 8> map;
  vector<array<int, 3> > cctv;//y, x, dir

  cin >> width >> height;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> map[i][j];
      if (1 <= map[i][j] && map[i][j] <= 5) {
        array<int, 3> coord = {i, j, 0};
        cctv.push_back(coord);
      }
    } 
  }
  space = width * height;
  solve(map, cctv, 0);
}