#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int T, N, M;
  cin >> T;
  while (T--) {
    cin >> N >> M;
    long long nums = 1;//mCn
    int denominator = 1;
    for (int i = M - N + 1; i <= M; i++) {
      nums *= i;
      nums /= denominator++;
    }
    cout << nums << endl;
  }
}