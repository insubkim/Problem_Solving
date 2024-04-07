#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int arr[50];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int cluster_size;
  cin >> cluster_size;

  long long cluster_cnt = 0;

  for (int i = 0; i < N; i++) {
    if (arr[i] == 0) continue;
    cluster_cnt += arr[i] / cluster_size;
    if (arr[i] % cluster_size != 0) cluster_cnt++;
  }

  cout << cluster_cnt * cluster_size << endl;
}