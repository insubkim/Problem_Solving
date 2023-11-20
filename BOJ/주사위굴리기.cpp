#include <iostream>
#include <vector>
#include <queue>

#define TOP 0
#define BOTTOM 1
#define FRONT 2
#define LEFT 3
#define RIGHT 4
#define BACK 5

using namespace std;

// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.
enum Dir {
  EAST = 1,
  WEST,
  NORTH,
  SOUTH,
};

int width, length;
int dice_x, dice_y;
int cmd_num;

vector<vector<int> >board;

queue<int> cmds;

int dice[6] = {0, };

void rollDice(int d1, int d2, int d3, int d4, Dir roll_direction){
  int tmp;

  tmp = dice[d4];
  dice[d4] = dice[d3];
  dice[d3] = dice[d2];
  dice[d2] = dice[d1];
  dice[d1] = tmp;

  if (roll_direction == EAST) dice_x++;
  else if (roll_direction == WEST) dice_x--;
  else if (roll_direction == SOUTH) dice_y++;
  else dice_y--;

  if (board[dice_y][dice_x] == 0) board[dice_y][dice_x] = dice[BOTTOM];
  else {
    dice[BOTTOM] = board[dice_y][dice_x];
    board[dice_y][dice_x] = 0;
  }
  cout << dice[TOP] << endl;
}

void solve(void){
  while (cmd_num--){
    int cmd = cmds.front();
    cmds.pop();
    if (cmd == EAST && dice_x  + 1 < width) rollDice(TOP, RIGHT, BOTTOM, LEFT, EAST);
    else if (cmd == WEST && dice_x - 1 >= 0) rollDice(TOP, LEFT, BOTTOM, RIGHT, WEST);
    else if (cmd == NORTH && dice_y - 1 >= 0) rollDice(TOP, BACK, BOTTOM, FRONT, NORTH);
    else if (cmd == SOUTH && dice_y + 1 < length) rollDice(TOP, FRONT, BOTTOM, BACK, SOUTH);
    // cout << "=========================" << endl;
    // cout << "DIRECTION :";
    // if (cmd == EAST) cout << "EAST" << "\n";
    // if (cmd == WEST) cout << "WEST" << "\n";
    // if (cmd == SOUTH) cout << "SOUTH" << "\n";
    // if (cmd == NORTH) cout << "NORTH" << "\n";

    // cout << " " << dice[BACK] << "\n";
    // cout << dice[LEFT] << dice[BOTTOM] <<dice[RIGHT] <<"\n";
    // cout << " " << dice[FRONT] << "\n";
    // cout << " " << dice[TOP] << "\n\n";
    // for (auto x : board){
    //   for (auto y : x)
    //     cout << y << " ";
    //   cout << '\n';
    // }

    // cout << "=========================\n" << endl;
  }
}

int main(){
  cin >> length >> width >> dice_x >> dice_y >> cmd_num;
  for (size_t i = 0; i < length; i++){
    vector<int> v;
    for (size_t j = 0; j < width; j++){
      int val;
      cin >> val;
      v.push_back(val);
    }
    board.push_back(v);
  }
  for (size_t i = 0; i < cmd_num; i++){
    int val;
    cin >> val;
    cmds.push(val);
  }
  solve();
  return 0;
}