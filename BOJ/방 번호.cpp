#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;
  int arr[10] = {0, };

  int r = 0;
  int six = 0;
  int nine = 0;
  while (N > 0) {
    int tmp;
    tmp = N % 10;
    arr[tmp]++;
    if (tmp == 9) nine++;
    else if (tmp == 6) six++;
    N /= 10;
    r++;
  }
  r -= nine > six ? six : nine;
  cout << r << endl;


}