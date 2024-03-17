#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  set<string> s[51];

 int n;
 cin >> n;

 for (int i = 0; i < n; i++) {
  string tmp;
  cin >> tmp;
  s[tmp.size()].insert(tmp);
 }

 for (int i = 1; i <= 50; i++) {
  for_each(s[i].begin(), s[i].end(), [](const string& v) {
    cout << v << "\n";
  });
 }
}