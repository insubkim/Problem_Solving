#include <iostream>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int length, width;
int robot_x, robot_y;
int dir;

int map[51][51] = {0, };

int room = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, 1};

void solve(int y, int x, int cur_dir){
  //현재 칸 청소 확인
  if (map[y][x] == 0) {
    room++;
    map[y][x] = 2;
  }
  //현재 4칸 중 청소 안된거 있는지 확인
  bool clean = false;
  for (size_t i = 0; i < 4; i++){
    int yy = y + dy[i];
    int xx = x + dx[i];
    if (0 <= yy && yy < length && 0 <= xx && xx < width && map[yy][xx] == 1) break ;
  }

  //없으면 뒤로가기
  //뒤로 못가면 끝!
  //있으면 반시계 90 회전
  //청소 안됐으면 한칸 전진
  //1. 반복

  if (clean) {
    //뒤로가기

    solve(y, x, cur_dir);
  } else {
    //회전

    solve(y, x, cur_dir);
  } 
}

int main(){
  cin >> length >> width >> robot_y >> robot_x >> dir;
  for (size_t i = 0; i < length; i++){
    for (size_t j = 0; j < width; j++){
      cin >> map[i][j];
    } 
  }
  solve(robot_y, robot_x, dir);
  cout << room << endl;
}