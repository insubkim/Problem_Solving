#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

int main() {
  string name;

  cin >> name;

  int arr[26] = {0,};
  for (auto x : name) {
    arr[x - 'A']++;
  }
  
  string front, back;
  for (int i = 0; i < 26; i++) {
    while (arr[i] / 2 > 0) {
      front.append(1, (char)(i + 'A'));
      back.insert(0, 1, (char)(i + 'A'));
      arr[i] -= 2;
    }
  }
  
  for (int i = 0; i < 26; i++)
    assert(arr[i] == 1 || arr[i] == 0);

  bool flag = false;
  for (int i = 0; i < 26; i++) {
    if (arr[i] % 2 && arr[i] > 0) {
      if (flag) {
        cout << "I'm Sorry Hansoo" << endl;
        return (0);
      }
      front.append(1, (char)(i + 'A'));
      flag = true;
    }
  }
  cout << front << back << endl;
}