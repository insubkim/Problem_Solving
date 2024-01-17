#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

int m = -1;
int width, height;

void  solve(array<array<int, 8>, 8> map, vector<array<int, 2> > cctv, int cnt) {

  vector<int> cctv_dir(cctv.size(), 0);

}


int main() {
  array<array<int, 8>, 8> map;
  vector<array<int, 2> > cctv;
  

  cin >> width >> height;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> map[i][j];
      if (1 <= map[i][j] && map[i][j] <= 5) {
        array<int, 2> coord = {i, j};
        cctv.push_back(coord);
      }
    } 
  }
  solve(map, cctv, 0);
}