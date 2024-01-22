#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int test_case;
  int start_x, start_y;
  int end_x, end_y;
  cin >> test_case ;
  while (test_case--) {
    cin >> start_x >> start_y >> end_x >> end_y;
    int planet_num;
    cin >> planet_num;
    int cnt = 0;
    while (planet_num--) {
      int x, y, r;
      cin >> x >> y >> r;
      bool is_start_in = (pow((x - start_x), 2) + pow((y - start_y), 2)) < pow(r, 2) ? true : false;
      bool is_end_in = (pow((x - end_x), 2) + pow((y - end_y), 2)) < pow(r, 2) ? true : false;
      if (is_start_in != is_end_in) cnt++;
    }
    cout << cnt << endl;
  }

}