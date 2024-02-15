#include <iostream>
#include <cassert>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
  
  int eratostenes[100001];
  memset(eratostenes, 1, sizeof eratostenes);
  eratostenes[0] = 0;
  eratostenes[1] = 0;
  
  int prime_factors_list[100001];
  memset(prime_factors_list, 0, sizeof prime_factors_list);

  for (int i = 2; i < 100001; i++) {
    if (!eratostenes[i]) continue;
    for (int j = i * 2; j < 100001; j += i) {
      eratostenes[j] = 0;
      int tmp = j;
      while (tmp % i == 0) {
        tmp /= i;
        prime_factors_list[j]++;
      }
    }
  }

  int A, B;
  cin >> A >> B;

  int cnt = 0;
  while (A <= B) {
    if (eratostenes[prime_factors_list[A]]) cnt++;
    A++;
  }

  cout << cnt << endl;
}