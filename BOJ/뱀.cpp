#include <vector>
#include <iostream>
#include <utility>
#include <queue>


using namespace std;

int box_size;
int apple_num;
vector<pair<int, int> > apple_coord;

enum direction {
  LEFT = 0,
  UP,
  RIGHT,
  DOWN,
};

enum Map_Identifier{
  EMPTY = 0,
  APPLE,
  SNAKE,
};

enum Status{
  LIVE = 0,
  DIE,
};

int snake_move_size;
queue<pair<int, int> > snake_moves;

int solve(void){
  int sec = 0;
  vector<vector<int> > board(box_size);
  for (int i = 0; i < box_size; i++)  board[i] = vector<int>(box_size, EMPTY);
  for (int i = 0; i < apple_num; i++) {
    int x = apple_coord[i].first;
    int y = apple_coord[i].second;
    board[y][x] = APPLE;
  }
  int status = LIVE;
  int head_dir = RIGHT;
  int head_x = 0;
  int head_y = 0;
  int tail_x = 0;
  int tail_y = 0;
  board[head_y][head_x] = SNAKE;
  queue<int> route;
  route.push(RIGHT);
  while (1){
    //move head
    if (snake_moves.front().first == sec){
      int rotate = snake_moves.front().second;
      if (rotate == LEFT){
        head_dir--;
      } else {
        head_dir++;
      }
      if (head_dir < 0){
        head_dir = DOWN;
      } else if (head_dir > DOWN){
        head_dir = LEFT;
      }
      snake_moves.pop();
    }
    //update route
    route.push(head_dir);
    //update coord
    if (head_dir == LEFT){
      head_x--;
    } else if (head_dir == RIGHT){
      head_x++;
    } else if (head_dir == UP){
      head_y--;
    } else {
      head_y++;
    }
    //die
    if (head_x < 0 || head_x >= box_size 
      || head_y < 0 || head_y >= box_size 
      || board[head_y][head_x] == SNAKE){
      status = DIE;
    }
    //time
    sec++;
    if (status == DIE) break;
    //update map-tail
    if (board[head_y][head_x] != APPLE){
      board[tail_y][tail_x] = EMPTY;
      int tail_dir = route.front();
      route.pop();
      if (tail_dir == LEFT){
        tail_x--;
      } else if (tail_dir == RIGHT){
        tail_x++;
      } else if (tail_dir == UP){
        tail_y--;
      } else {
        tail_y++;
      }
    }
    //update map-head
    board[head_y][head_x] = SNAKE;
  }  
  return sec;
}

int main(){
  cin >> box_size >> apple_num;
  for (int i = 0; i < apple_num; i++){
    int x,y;
    cin >> y >> x;
    apple_coord.push_back(make_pair(x - 1, y - 1));
  }
  cin >> snake_move_size;
  for (int i = 0; i < snake_move_size; i++){
    int sec;
    char dir;
    cin >> sec >> dir;
    snake_moves.push(make_pair(sec, dir == 'L' ? LEFT : RIGHT));
  }  
  int sec = solve();
  cout << sec << endl;
  return 0;
}

