#include <iostream>
#include <cmath>
#include <cassert>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  
  string id[1000];

  for (int i = 0; i < N; i++) {
    string in;
    cin >> in;
    id[i] = in;
  }

  int last_idx = id[0].size() - 1;
  while (last_idx >= 0) {
    bool flag = true;
    unordered_set<string> ids;
    for (int i = 0; i < N; i++) {
      string v = id[i].substr(last_idx);
      if (ids.count(v)) {
        flag = false;
        break ;
      }
      ids.insert(v);
    }
    if (flag) break ;
    last_idx--;
  }
  assert(last_idx != -1);//문제가 이상한거임.
  cout << id[0].size() - last_idx;


}