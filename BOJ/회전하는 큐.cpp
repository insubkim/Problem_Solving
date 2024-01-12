#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <numeric>

using namespace std;

int main() {
  int queue_size;
  int extract_size;

  cin >> queue_size >> extract_size;

  deque<int> queue(queue_size);
  iota(queue.begin(), queue.end(), 1);

  int operation_cnt = 0;
  for (int i = 0; i < extract_size; i++) {
    int extract;
    cin >> extract;
    deque<int>::iterator it = queue.begin();
    int a;
    while (it != queue.end()) {
      if (*it == extract) {
        a = it - queue.begin();
        break;
      }
      it++;
    }
    deque<int>::reverse_iterator rit = queue.rbegin();
    while (rit != queue.rend()) {
      if (*rit == extract) {
        if (a < rit - queue.rbegin()) {
          
        } else {

        }
        a = min((int)a, (int)(rit - queue.rbegin()));
        break;
      }
      rit++;
    }
    operation_cnt += a;
  }
  cout << operation_cnt << endl;
}