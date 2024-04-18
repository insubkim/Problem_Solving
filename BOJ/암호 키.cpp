#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    long long num;
    cin >> num;

    bool yes = true;
    for (int div = 2; div < sqrt(num) && div <= 1000000; div++) {
      if (num % div == 0) {
        yes = false;
        break ;
      }
    }
    cout << (yes ? "YES" : "NO") << endl;
  }
}
