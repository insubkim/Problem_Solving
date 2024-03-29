#include <iostream>
#include <set>

using namespace std;

int main() {
  int N;
  cin >> N;

  int num = 0;
  while (N--) {
    string word;
    cin >> word;

    set<char> s;
    char prev = 0;
    bool f = true;
    for (auto x : word) {
      if (prev == 0) {
        prev = x;
        s.insert(x);
        continue;
      }
      if (x == prev) continue;
      if (s.count(x)) {
        f = false;
        break;
      }
      prev = x;
      s.insert(x);
    }
    if (f) num++;
  }
  cout << num << endl;
}