#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, B, C;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> B >> C;
  int num = 0;
  for (int i = 0; i < N; i++) {
    num++;
    A[i] -= B;
    if (A[i] > 0) {
      num += A[i] / C;
      num += A[i] % C == 0 ? 0 : 1;
    }
  }
  cout << num << endl;
  return 0;
}