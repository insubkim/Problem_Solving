#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;

  int ball = 1;
  while (N--) {
    int a, b;
    cin >> a >> b;
    if (a == ball) ball = b;
    else if (b == ball) ball = a;
  }
  cout << ball << endl;
}