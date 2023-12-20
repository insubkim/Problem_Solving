#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s)
{
    bool    flag;
    do {
      flag = false;

      string  tmp;
      for (size_t i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && s[i] == s[i + 1]) {
          flag = true;
          i++;
        } else {
          tmp.push_back(s[i]);
        }
      }
      s = tmp;
    } while (flag);
    return !s.size();
}


#include <iostream>
int  main() {
  int a = solution("caabbc");
  cout << a << endl;
}