#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

void  solve(int width, int height, array<array<int, 8>, 8>& map, vector<array<int, 2> >& cctv) {
  int unseen = width * height;

  vector<int> cctv_dir(cctv.size(), 0);

}


int main() {
  int width, height;
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
  solve(width, height, map, cctv);
}