#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  bool f = true;
  for (auto &x : s) {
    if (x == ' ') {
      f = true;
    } else if (f) {
      f = false;
      if (islower(x)) x = toupper(x);
    } else if (isupper(x)) {
      x = tolower(x);
    }
  }
  return s;
}

#include <iostream>
int main() {
  cout << solution("      123a   abc123s  ssskkk  4a 23a a123B aBCD") << endl;
  return 0;
}