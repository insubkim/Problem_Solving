#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

void  getGear(int gear[][8]) {
  string input;

  for (int i = 0; i < 4; i++) {
    cin >> input;
    for (int j = 0; j < 8; j++) {
      gear[i][j] = input[j] - '0';
    }
  }
}

int getMagnet(int gear[][8], int head[], int gear_num, int offset) {
  int idx = (head[gear_num - 1] + offset + 8) % 8;
  return gear[gear_num - 1][idx];
}

void  checkLeft(int moved_gear, int head[], int gear[][8], int move[]) {
  if (moved_gear == 1) return;

  int target_gear = moved_gear - 1;

  int target_gear_magnet3 = getMagnet(gear, head, target_gear, 2);
  int moved_gear_magnet9 = getMagnet(gear, head, moved_gear, -2);

  if (target_gear_magnet3 != moved_gear_magnet9) {
    move[target_gear - 1] = -move[moved_gear - 1];
    checkLeft(target_gear, head, gear, move);
  }
}

void  checkRight(int moved_gear, int head[], int gear[][8], int move[]) {
  if (moved_gear == 4) return;

  int target_gear = moved_gear + 1;

  int moved_gear_magnet3 = getMagnet(gear, head, moved_gear, 2);
  int target_gear_magnet9 = getMagnet(gear, head, target_gear, -2);

  if (moved_gear_magnet3 != target_gear_magnet9) {
    move[target_gear - 1] = -move[moved_gear - 1];
    checkRight(target_gear, head, gear, move);
  }
}

void  init(int move[], int target_gear, int operation) {
  fill_n(&move[0], 4, 0);
  move[target_gear - 1] = operation;
}

void  moveGear(int head[], int move[]) {
  for (int i = 0; i < 4; i++) {
    head[i] = (head[i] - move[i] + 8) % 8;
  }
}

void  solve(int gear[][8]) {
  int operation_cnt;
  int targetGear;//선택된 기어
  int operation;//1 시계, -1 반시계
  int head[4] = {0}; // 0번 : 12시, 1번 : 1시, 2번 : 3시 ... 
  int move[4]; // 움직임 여부

  cin >> operation_cnt;
  while (operation_cnt--) {
    cin >> targetGear >> operation;
    init(move, targetGear, operation);
    checkLeft(targetGear, head, gear, move);
    checkRight(targetGear, head, gear, move);
    moveGear(head, move);
  }
  int sum = 0;
  sum += getMagnet(gear, head, 1, 0) ? 1 : 0;
  sum += getMagnet(gear, head, 2, 0) ? 2 : 0;
  sum += getMagnet(gear, head, 3, 0) ? 4 : 0;
  sum += getMagnet(gear, head, 4, 0) ? 8 : 0;
  cout << sum << endl;
}

int main(void) {
  int gear[4][8];
  getGear(gear);
  solve(gear);
}