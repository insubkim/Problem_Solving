#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int main() {
  string L, R;
  
  cin >> L >> R;
  

  int cnt = 0;
  if (L.size() == R.size()) {
    for (size_t i = 0; i < L.size(); i++) {
      if (L[i] == R[i] && L[i] == '8') cnt++;
      else if (L[i] != R[i]) break;
    }  
  }

  cout << cnt << endl;
}