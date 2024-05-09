#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int num = 0;
  for (int i = 0; i < s.size();) {
    num++;
    for (auto c : to_string(num)) {
      if (c == s[i]) i++;
      if (i == s.size()) break ;
    }
  }

  cout << num << endl;
}