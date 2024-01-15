#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
  int width, height;
  array<array<int, 8>, 8> map;

  cin >> width >> heigth;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> map[i][j];
    } 
  }

}