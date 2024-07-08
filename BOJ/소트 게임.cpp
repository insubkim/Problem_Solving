#include <iostream>
#include <cassert>

using namespace std;

int N, K;
int min_rotate = -1;

int main() {
  cin >> N >> K;

  int arr[9] = {0, };
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  solve();

  cout << min_rotate << endl;

}