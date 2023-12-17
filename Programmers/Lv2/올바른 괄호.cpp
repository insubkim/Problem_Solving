#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
  stack<char> st;
  for (auto x : s) {
    if (x == '(')         st.push(')');
    else if (st.empty())  return false;
    else                  st.pop(); 
  }
  return st.empty() ? true : false;
}