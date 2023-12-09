#include <iostream>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define EMPTY_DIRTY 0
#define WALL 1
#define EMPTY_CLEAN 2


using namespace std;

int length, width;
int robot_x, robot_y;
int dir;

int map[51][51] = {0, };

int room = 0;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

/* bool check_element_match(int y, int x, int element)
  check length, width 
  then, check element
 */
bool check_element_match(int y, int x, int element) {
  return 0 <= y && y < length && 0 <= x && x < width && map[y][x] == element;
}

/* int getOppositeDir(int dir)
  NORTH + 2 = SOUTH
  EAST + 2 = WEST
  (SOUTH + 2) % 4 = NORTH
  (NORTH + 2) % 4 = EAST
 */
int getOppositeDir(int dir){
  return (dir + 2) % 4;
}

/* int getRotateDir(int dir)
  dir - 1 => 90 degree opposite rotation 
  but NORTH - 1 == -1 
  so, + 4 and modular 4
*/
int getRotateDir(int dir){
  return ((dir - 1) + 4) % 4;
}

void printmap(int y, int x){
  cout << "x, y :" << x << " : " << y << std::endl;
  for (int i = 0; i < length; i++){
    for (int j = 0; j < width; j++){
      cout << map[i][j] << " ";
    } 
    cout << endl;
  }
} 

void solve(int y, int x, const int cur_dir){
  // printmap(y, x);
  //현재 칸 청소 확인
  if (map[y][x] == EMPTY_DIRTY) {
    room++;
    map[y][x] = EMPTY_CLEAN;
  }
  //현재 4칸 중 청소 안된거 있는지 확인
  bool dirty = false;
  for (size_t i = 0; i < 4; i++){
    int yy = y + dy[i];
    int xx = x + dx[i];
    if (check_element_match(yy, xx, EMPTY_DIRTY)) {
      dirty = true;
      break ;
    }
  }

  //dirty 없으면 뒤로가기
  //뒤로 못가면 끝!
  //있으면 반시계 90 회전
  //청소 안됐으면 한칸 전진
  //1. 반복

  if (!dirty) {
    int op_dir = getOppositeDir(cur_dir);
    int yy = y + dy[op_dir];
    int xx = x + dx[op_dir];
    //뒤로가기
    if (check_element_match(yy, xx, EMPTY_DIRTY) || check_element_match(yy, xx, EMPTY_CLEAN)) {
      solve(yy, xx, cur_dir);
    }
  } else {
    //회전
    int yy, xx, rotate_dir = cur_dir;
    for (int i = 0; i < 4; i++) {
      rotate_dir = getRotateDir(rotate_dir);
      yy = y + dy[rotate_dir];
      xx = x + dx[rotate_dir];
      if (check_element_match(yy, xx, EMPTY_DIRTY)){
        solve(yy, xx, rotate_dir);
        break ;
      }
    }
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