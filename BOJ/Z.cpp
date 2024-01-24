#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long N, c, r, cnt;
bool end_flag = false;

void  solve(void) {
  long long n = pow(2, N);
  long long x = 0;
  long long y = 0;
  
  while (n != 1) {
    long long box_size = n / 2;
    if (x <= c && c < x + box_size && y <= r && r < y + box_size) {//1사분면
      (void)n;
    } else if (x + box_size <= c && c < x + n && y <= r && r < y + box_size) {//2사분면 
      x += box_size;
      cnt += pow(box_size, 2);
    } else if (x <= c && c < x + box_size && y + box_size <= r && r < y + n) {//3사분면
      y += box_size;
      cnt += pow(box_size, 2) * 2;
    } else {//4사분면
      cnt += pow(box_size, 2) * 3;
      x += box_size;
      y += box_size;
    }
    n /= 2;
  }
}

int main() {

  cin >> N >> r >> c;
  // int arr[8][8] = {
  //   {0, 1, 4, 5, 16, 17, 20, 21},
  //   {2, 3, 6, 7, 18, 19, 22, 23},
  //   {8, 9, 12, 13, 24, 25, 28, 29},
  //   {10, 11, 14, 15, 26, 27, 30, 31},
  //   {32, 33, 36,37, 48, 49, 52, 53},
  //   {34, 35, 38, 39, 50, 51, 54, 55},
  //   {40, 41, 44, 45, 56, 57, 60,61},
  //   {42, 43, 46, 47, 58, 59, 62, 63}
  // };
  // for (int i = 0; i < 8; i++) {
  //   for (int j = 0; j < 8; j++) {
  //     cnt = 0;
  //     N = 3;
  //     r = i;
  //     c = j;
  //     solve();
  //     if (arr[i][j] != cnt) {
  //       cout << i << " , " << j << " cnt = " << cnt << " ans = " << arr[i][j] << endl; 
  //     }
  //   }  
  // }
  solve();
  cout << cnt << endl;
}