#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long N, r, c, cnt;
bool end_flag = false;

void  solve(long long x, long long y, long long n) {
  if (end_flag) return ;
  if (n == 2) {
    if (x == c && y == r) {
      end_flag = true;
      return ;
    }
    cnt++;
    if (x + 1 == c && y == r){
      end_flag = true;
      return ;
    }
    cnt++;
    if (x == c && y + 1 == r){
      end_flag = true;
      return ;
    }
    cnt++;
    if (x + 1 == c && y + 1 == r){
      end_flag = true;
      return ;
    }
    cnt++;
    return ;
  }
  //왼쪽 위
  solve(x, y, n / 2);
  //오른쪽 위
  solve(x + n / 2, y, n / 2);
  //왼쪽 아래
  solve(x, y + n / 2, n / 2);
  //오른쪽 아래
  solve(x + n / 2, y + n / 2, n / 2);
}

int main() {
  cin >> N >> r >> c;
  N = pow(2, N);
  solve(0, 0, N);
  cout << cnt << endl;
}