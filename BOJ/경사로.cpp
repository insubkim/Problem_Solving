#include <iostream>
#include <algorithm>

using namespace std;

void  getInput(int& map_size, int& stair_length, int map[][100]) {
  cin >> map_size >> stair_length;
  for (int i = 0; i < map_size; i++) {
    for (int j = 0; j < map_size; j++) {
      cin >> map[i][j];
    }
  }
}

bool  putStair(const int map_size, int stair_length, int map[][100], int y, int x, int dy, int dx, int cur_height) {
  int stair[100][100];

  std::fill_n(&stair[0][0], 100 * 100, 0);
  
  if (map[y][x] + 1 != cur_height && map[y][x] - 1 != cur_height)
    return false;
  
  if (map[y][x] - 1 == cur_height) {
    for (int i = 0; i < stair_length; i++) {
      y -= dy;
      x -= dx;
      if (0 > x || x >= map_size || 0 > y || y >= map_size) return false;
      if (map[y][x] == cur_height && stair[y][x] == 0) stair[y][x] = 1;
      else return false;
    }
  } else if (map[y][x] + 1 == cur_height) {
    for (int i = 0; i < stair_length; i++) {
      if (map[y][x] + 1 == cur_height && stair[y][x] == 0) stair[y][x] = 1;
      else return false;
      y += dy;
      x += dx;
      if (0 > x || x >= map_size || 0 > y || y >= map_size) return false;
    }
  }
  return true;
}

bool  canPass(const int map_size, int stair_length, int map[][100], int y, int x, int dy, int dx) {
  int stair[100][100];
  std::fill_n(&stair[0][0], 100 * 100, 0);

  int cur_height = map[y][x];
  
  while (y < map_size && x < map_size) {
    if (map[y][x] != cur_height && map[y][x] + 1 != cur_height && map[y][x] - 1 != cur_height)
        return false;
    int xx = x;
    int yy = y;
    if (map[y][x] - 1 == cur_height) {
      for (int i = 0; i < stair_length; i++) {
        yy -= dy;
        xx -= dx;
        if (0 > xx || xx >= map_size || 0 > yy || yy >= map_size) return false;
        if (map[yy][xx] == cur_height && stair[yy][xx] == 0) stair[yy][xx] = 1;
        else return false;
      }
    } else if (map[y][x] + 1 == cur_height) {
      for (int i = 0; i < stair_length; i++) {
        if (0 > xx || xx >= map_size || 0 > yy || yy >= map_size) return false;
        if (map[yy][xx] + 1 == cur_height && stair[yy][xx] == 0) stair[yy][xx] = 1;
        else return false;
        yy += dy;
        xx += dx;
      }
    }


    cur_height = map[y][x];
    y += dy;
    x += dx;
  }
  return true;
}

void  solve(const int map_size, int stair_length, int map[][100]) {
  int path = 0;

  for (int i = 0; i < map_size; i++) {
    if (canPass(map_size, stair_length, map, 0, i, 1, 0)) path++; //down
    if (canPass(map_size, stair_length, map, i, 0, 0, 1)) path++; //right
  }
  cout << path << endl;
}
void myfunction(int i) {  // function:
  std::cout << ' ' << i;
}

int main() {
  int map_size, stair_length;
  int map[100][100];

  std::fill_n(&map[0][0], 100 * 100, 0);
  getInput(map_size, stair_length, map);
  // for (int i = 0;  i < map_size; i++) {
  //   for (int j = 0;  j < map_size; j++) {
  //     cout << map[i][j] << " ";
  //   } 
  //   cout << endl;
  // }
  solve(map_size, stair_length, map);
}