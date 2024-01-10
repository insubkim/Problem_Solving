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

void  checkLeft(int moved_gear, int head[], int gear[][8], int move[]) {
  if (moved_gear == 0) return;

  int target_gear = moved_gear - 1;

  int target_gear_magnet3 = gear[target_gear][(head[target_gear] + 2) % 8];
  int moved_gear_magnet9 = gear[moved_gear][head[moved_gear] - 2 < 0 ? (head[moved_gear] - 2) + 8 : head[moved_gear] - 2];

  if (target_gear_magnet3 != moved_gear_magnet9) {
    move[target_gear] = -move[moved_gear];
    checkLeft(target_gear, head, gear, move);
  }
}

void  checkRight(int moved_gear, int head[], int gear[][8], int move[]) {
  if (moved_gear == 3) return;

  int target_gear = moved_gear + 1;

  int moved_gear_magnet3 = gear[moved_gear][(head[moved_gear] + 2) % 8];
  int target_gear_magnet9 = gear[target_gear][head[target_gear] - 2 < 0 ? (head[target_gear] - 2) + 8 : head[target_gear] - 2];

  if (moved_gear_magnet3 != target_gear_magnet9) {
    move[target_gear] = -move[moved_gear];
    checkRight(target_gear, head, gear, move);
  }
}

void  init(int move[], int target_gear, int operation) {
  fill_n(&move[0], 4, 0);
  move[target_gear] = operation;
}

void  moveGear(int head[], int move[]) {
  for (int i = 0; i < 4; i++) {
    head[i] += move[i];
  }
}

void  solve(int gear[][8]) {
  int operation_cnt;
  int targetGear;
  int operation;//1 시계, -1 반시계
  int head[4] = {0, 0, 0, 0}; // 12시 인덱스
  int move[4]; // 움직임 여부

  cin >> operation_cnt;
  while (operation_cnt--) {
    cin >> targetGear >> operation;
    init(move, targetGear - 1, operation);
    checkLeft(targetGear - 1, head, gear, move);
    checkRight(targetGear - 1, head, gear, move);
    moveGear(head, move);
  }
  int sum = 0;
  sum += gear[0][head[0]] ? 1 : 0;
  sum += gear[1][head[1]] ? 2 : 0;
  sum += gear[2][head[2]] ? 4 : 0;
  sum += gear[3][head[3]] ? 8 : 0;
  cout << sum << endl;
}

int main(void) {
  int gear[4][8];
  getGear(gear);
  solve(gear);
}