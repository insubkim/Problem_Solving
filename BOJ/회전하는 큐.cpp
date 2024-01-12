#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <numeric>

using namespace std;

template <typename T>
T search_val(T begin, T end, int val) {
  while (begin != end) {
    if (*begin == val) {
      return begin;
    }
    begin++;
  }
  return begin;
}

void  rotate(deque<int>& q, int dir) {
  while (dir > 0) {
    int val = q.front();
    q.pop_front();
    q.push_back(val);
    dir--;
  }
  while (dir < 0) {
    int val = q.back();
    q.pop_back();
    q.push_front(val);
    dir++;
  }
}

int main() {
  int queue_size;
  int extract_size;

  cin >> queue_size >> extract_size;

  deque<int> q(queue_size);
  iota(q.begin(), q.end(), 1);

  int operation_cnt = 0;
  for (int i = 0; i < extract_size; i++) {
    int extract;
    cin >> extract;
    int a = search_val(q.begin(), q.end(), extract) -  q.begin();
    int b = search_val(q.rbegin(), q.rend(), extract) - q.rbegin() + 1;
    if (a < b) {
      rotate(q, a);
    } else {
      rotate(q, -b);
    }
    q.pop_front();
    operation_cnt += a < b ? a : b;
  }
  cout << operation_cnt << endl;
}