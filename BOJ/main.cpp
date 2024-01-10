#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
  int a[2][3] = {
    { 1, 2, 3 }, 
    { 4, 5, 6 }
  };
  int b[2][3];
  std::copy(&a[0][0], &a[0][0] + sizeof(a) / sizeof(int), &b[0][0]);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << b[i][j] << " ";
    } 
    cout << endl;
  }
}