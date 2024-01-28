#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int N,M,K;
  cin >> N >> M;
  int nums[100001] = {0};
  for (int i = 1; i < N + 1; i++) {
    cin >> K;
    nums[i] = nums[i - 1] + K;
  }

  for (int i = 0; i < M; i++) {
    int start, end;
    cin >> start >> end;
    cout << nums[end] - nums[start - 1] << '\n'; 
  }
}