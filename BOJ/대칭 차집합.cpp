#include <iostream>
#include <cmath>
#include <cassert>
#include <cstring>
#include <set>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  set<int> arr;

  for (int i = 0; i < a; i++) {
    int v;
    cin >> v;
    arr.insert(v);
  }
  int rtn = a + b;
  for (int i = 0; i < b; i++) {
    int v;
    cin >> v;
    if (arr.count(v)) 
      rtn -= 2;
  }
  cout << rtn << endl;
}
