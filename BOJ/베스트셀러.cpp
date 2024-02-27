#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
#include <cstring>
#include <map>

using namespace  std;

int main() {
  int N;
  cin >> N;

  int m = 0;
  string m_name;

  map<string, int> maps;
  for (int i = 0; i < N; i++) {
    string name;
    cin >> name;

    if (maps.count(name)) maps[name]++;
    else maps[name] = 1;

    if (m < maps[name]) {
      m = maps[name];
      m_name = name;
    } else if (m == maps[name]) {
      assert(name != m_name);
      if (strcmp(m_name.c_str(), name.c_str()) > 0) {
        m = maps[name];
        m_name = name;
      } 
    }
  }
  cout << m_name << endl;
}