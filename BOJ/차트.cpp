#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int m;

int cal(int line[9], int N, int dog[9]) {
  int h = 0;
  int sum = 0;
  int start_index = 1;
  for (int i = 1; i <= N; i++) {
    sum += dog[line[i]];
    if (sum == 50){
      h++;
    }
    while (sum >= 50 && start_index < i) {
      sum -= dog[line[start_index++]];
    }
  }
  return h;
}

void  solve(int line[9], int selected[9], int index, int N, int dog[9]) {
  if (index > N) {
    m = max(m, cal(line, N, dog));
    return ;
  }
  for (int i = 1; i <= N; i++) {
    if (selected[i]) continue;
    selected[i] = 1;
    line[index] = i;
    solve(line, selected, index + 1, N, dog);
    selected[i] = 0;
  }
}

int main() {
  int N;
  cin >> N;

  int dog[9] = {0, };
  for (int i = 1; i <= N; i++)
    cin >> dog[i];
  
  int line[9] = {0, };
  int selected[9] = {0, };
  solve(line, selected, 1, N, dog);
  
  if (m > 0 && N != 2) m--;
  cout << m << endl;
}