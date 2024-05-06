#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

typedef enum e_dir {
  UP = 0,
  LEFT,
  FRONT,
  RIGHT,
  BACK,
  BOTTOM
} t_dir;

int N;
int dices[10001][6];

e_dir get_up_dir(e_dir bottom) {
  switch (bottom)
  {
  case UP:
    return BOTTOM;
  case LEFT:
    return RIGHT;
    break;
  case FRONT:
    return BACK;
    break;
  case RIGHT:
    return LEFT;
    break;
  case BACK:
    return FRONT;
    break;
  case BOTTOM:
    return FRONT;
    break;
  default:
    break;
  }
  return UP;
}

int solve(e_dir bottom, int index) {
  int max_num = 0;
  e_dir up = get_up_dir(bottom);

  std::initializer_list<e_dir> all_E = {UP, LEFT, FRONT, RIGHT, BACK, BOTTOM};
  for (auto e : all_E) {
    if (e == bottom || e == up) continue;
    max_num = max(max_num, dices[index][e]);
  }

  if (index == N) return max_num;

  int up_val = dices[index][up];
  e_dir next_bottom;
  for (auto e : all_E) {
    if (up_val == dices[index + 1][e]) {
      next_bottom = e;
      break ;
    }
  }
  return solve(next_bottom, index + 1) + max_num; 
}

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> dices[i][UP] >> dices[i][LEFT] >> dices[i][FRONT] \
        >> dices[i][RIGHT] >> dices[i][BACK] >> dices[i][BOTTOM]; 
  }

  int max_sum = 0;
  max_sum = max(max_sum, solve(UP, 1));
  max_sum = max(max_sum, solve(LEFT, 1));
  max_sum = max(max_sum, solve(FRONT, 1));
  max_sum = max(max_sum, solve(RIGHT, 1));
  max_sum = max(max_sum, solve(BACK, 1));
  max_sum = max(max_sum, solve(BOTTOM, 1));

  cout << max_sum << endl;
  
}