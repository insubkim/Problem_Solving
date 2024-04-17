#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
  int pipe[1001] = {0, };
  int N,L;
  cin >> N >> L;

  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    pipe[tmp] = 1;
  }

  int tape = 0;
  for (int i = 1; i <= 1000; i++) {
    int tmp_L = L;
    int j = i;
    while (tmp_L && j <= 1000 && pipe[j]) {
      if (tmp_L == L) tape++;
      pipe[j++] = 0;
      tmp_L--;
    }
  }
  cout << tape << endl;


}