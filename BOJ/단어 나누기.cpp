#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  string r = "~";
  for (int i = 0; i < s.size() - 2; i++) {
    for (int j = i + 1; j < s.size() - 1; j++) {
      string val;
      
      for (int s1 = i; s1 >= 0; s1--) val += s[s1];
      for (int s2 = j; s2 >= i + 1; s2--) val += s[s2];
      for (int s3 = s.size() - 1; s3 >= j + 1; s3--) val += s[s3];
      if (val < r) r = val;
    } 
  }
  cout << r << endl;
}