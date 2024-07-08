#include <iostream>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  while (N--) {
    string in;
    cin >> in;
    if ((in.back() - '0') % 2)  cout << "odd" << endl;
    else                        cout << "even"  << endl;
  }
}