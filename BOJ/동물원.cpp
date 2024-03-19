#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;

  long long arr[100001][3];
  arr[1][0] = 1;//none
  arr[1][1] = 1;//left
  arr[1][2] = 1;//right


  for (int i = 2; i <= N; i++) {
    arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % 9901;
    arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % 9901;
    arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % 9901;
    // assert(arr[i][0] >= 0 && arr[i][1] >= 0 && arr[i][2] >= 0);
  }
  cout << (arr[N][0] + arr[N][1] + arr[N][2]) % 9901 << endl;
}