#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> st;

    for (size_t i = 0; i < s.size(); i++) {
      if (!st.empty() && st.top() == s[i]) {
        st.pop();
        continue ;
      } 
      st.push(s[i]);
    }

    while (!st.empty()) {
      char top = st.top();
      st.pop();
      if (!st.empty() && st.top() == top) {
        st.pop();
        continue;
      }
      st.push(top);
      break ;
    }
    return st.empty();
}


#include <iostream>
int  main() {
  int a = solution("baabaa");
  cout << a << endl;
}