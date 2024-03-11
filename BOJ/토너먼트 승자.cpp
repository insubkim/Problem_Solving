#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  long double win[3][8];

  //1
  for (int i = 0; i < 8; i++) {
    int win_rate;
    cin >> win_rate;
    win[0][i] = (long double)win_rate / 100.0;
  }
  //2
  int arr[8][2] = {
    {2, 3},
    {2, 3},
    {0, 1},
    {0, 1},
    {6, 7},
    {6, 7},
    {4, 5},
    {4, 5}
  };
    //1 3 4
    //2 3 4
    //3 1 2
    //4 1 2
    //5 7 8
    //6 7 8
    //7 5 6
    //8 5 6
  
  for (int i = 0; i < 8; i++) {
    win[1][i] = win[0][i] * win[0][arr[i][0]] ;
    win[1][i] += win[0][i] * win[0][arr[i][1]];
  }
  for (int i = 0; i < 8; i++) {
    cout << win[1][i] << (i == 7 ? "\n" : " ");
  }
  //3
  int arr2[8][4] = {
    {4, 5, 6, 7},
    {4, 5, 6, 7},
    {4, 5, 6, 7},
    {4, 5, 6, 7},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
    {0, 1, 2, 3}
  };
  for (int i = 0; i < 8; i++) {
    win[2][i] = win[1][i] * win[1][arr2[i][0]];
    win[2][i] += win[1][i] * win[1][arr2[i][1]];
    win[2][i] += win[1][i] * win[1][arr2[i][2]];
    win[2][i] += win[1][i] * win[1][arr2[i][3]];
  }

  for (int i = 0; i < 8; i++) {
    cout << win[2][i] << (i == 7 ? "\n" : " ");
  }
}