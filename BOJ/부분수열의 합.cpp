#include <iostream>

using namespace std;

int N, S, cnt;
int arr[20];

void  solve(int start, int rst) {
  if (start == N) {
    if (rst == S) cnt ++;
    return;
  }
  solve(start + 1, rst + arr[start]);
  solve(start + 1, rst);
}

int main() {
  cin >> N >> S;

  for (int i = 0; i < N; i ++) {
    cin >> arr[i];
  }
  solve(0, 0);
  if (S == 0) cnt--;
  cout << cnt << endl;
}