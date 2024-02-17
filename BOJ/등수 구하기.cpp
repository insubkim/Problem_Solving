#include <iostream>

using namespace std;

int main() {
  int N, S, P;
  cin >> N >> S >> P;

  int rank = 1;
  bool register_flag = false;
  for (int i = 0; i < N && i < P; i++) {
    int score;
    cin >> score;
    if (score < S) {
      register_flag = true;
      break;
    }
    else if (score > S) rank++;
  }
  if (N < P) register_flag = true;
  if (rank <= P && register_flag)  cout << rank << endl;
  else cout << -1 << endl;

}