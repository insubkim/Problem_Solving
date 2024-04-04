#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int dx[8] = { 1, 2,  2,  1, -1, -2, -2, -1};
int dy[8] = { 2, 1, -1, -2, -2, -1,  1,  2};

int main() {
  int x, y;
  bool invalid;
  bool arr[36] = {false, };
  int sx, sy;

  for (int i = 0; i < 36; i++) {
    string in;
    cin >> in;

    int xx,yy;
    xx = in[0] - 'A';
    yy = in[1] - '1';
    

    if (i == 0) {
      sx = x = xx;
      sy = y = yy;
      continue;
    }

    invalid = true;
    for (int j = 0; j < 8; j++) {
      if (x + dx[j] == xx && y + dy[j] == yy) {
        x = xx;
        y = yy;
        invalid = false;
        break;
      }
    }
    if (invalid) break ;

    if (arr[y * 6 + x]) {
      invalid = true;
      break ;
    }
    arr[y * 6 + x] = true;

    if (i == 35) {
      invalid = true;
      for (int j = 0; j < 8; j++) {
        if (x + dx[j] == sx && y + dy[j] == sy) {
          invalid = false;
          break;
        }
      }
    }
  }
  cout << (invalid ? "Invalid" : "Valid") << endl;
}