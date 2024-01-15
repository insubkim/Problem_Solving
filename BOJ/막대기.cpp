#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[8] = {64, 32, 16, 8, 4, 2, 1};
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    if (n == arr[i]) {
      cnt++;
      break ;
    } else if (n > arr[i]) {
      n -= arr[i];
      cnt++;
    }
  }
  cout << cnt;
}