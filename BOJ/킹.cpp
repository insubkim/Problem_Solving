#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int map[8][8];
char lo_king[2];
char lo_rock[2];

int n;

int dx[255];
int dy[255];

bool  check_map_range(int x, int y) {
  return 0 <= x && x < 8 \
    &&  0 <= y && y < 8;  
}

int main() {
  cin >> lo_king[0] >> lo_king[1];
  cin >> lo_rock[0] >> lo_rock[1];
  lo_king[0] = lo_king[0] - 'A'; lo_king[1] = 8 - (lo_king[1] - '0');
  lo_rock[0] = lo_rock[0] - 'A'; lo_rock[1] = 8 - (lo_king[1] - '0');
  
  dx['R'] = 1; dx['L'] = -1; dx['B'] = 0; dx['T'] = 0;
  dy['R'] = 0; dy['L'] =  0; dy['B'] = 1; dy['T'] = -1;

  cin >> n;
  for (int i = 0; i < n; i++) {
    string in;
    cin >> in;

    int dxx = 0;
    int dyy = 0;

    for (size_t j = 0; j < in.size(); j++) {
      dxx += dx[in[j]];
      dyy += dy[in[j]];
    }

    int x = lo_king[0] + dxx;
    int y = lo_king[1] + dyy;

    if (!check_map_range(x, y)) continue;
    if (x == lo_rock[0] && y == lo_rock[1]) {
      if (!check_map_range(lo_rock[0] + dxx, lo_rock[1] + dyy)) continue;
      lo_king[0] += dxx; lo_king[1] += dyy;
      lo_rock[0] += dxx; lo_rock[1] += dyy;
    } else {
      lo_king[0] = x;
      lo_king[1] = y;
    }
  }
  cout << (char)(lo_king[0] + 'A') << 8 - lo_king[1] << endl;
  cout << (char)(lo_rock[0] + 'A') <<  8 - lo_rock[1] << endl;
}