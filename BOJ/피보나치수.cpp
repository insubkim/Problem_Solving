#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;

  int a = 0;
  int b = 1;
  int c = b;

  for (int i = 2; i <= N; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  cout << c << endl;
}