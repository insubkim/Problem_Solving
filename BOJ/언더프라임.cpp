#include <iostream>
#include <cassert>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
  
  int eratostenes[100002] = {0, };

  memset(eratostenes, 1, sizeof eratostenes);
  eratostenes[1] = 0;
  for (int i = 2; i * i < 100002; i++) {
    if (!eratostenes[i]) continue;
    for (int j = i * i; j < 100002; j += i) 
      eratostenes[j] = 0;
  }

  int A, B;

  cin >> A >> B;
  int cnt = 0;
  
  int prime_factors_list[100002];
  memset(prime_factors_list, -1, sizeof prime_factors_list);
  prime_factors_list[1] = 0;

  while (A <= B) {
    int tmp = A;
    if (eratostenes[A]) {
      A++;
      continue;
    }
    // 소인수 갯수 구하기
    int prime_factors = 0;
    int div = 2;
    while (tmp != 1) {
      if (prime_factors_list[tmp] != -1) {
        prime_factors += prime_factors_list[tmp];
        break ;
      }
      if (tmp % div)  div++;
      else {
        tmp /= div;
        prime_factors++;
      }
    }
    prime_factors_list[A] = prime_factors;
    // 갯수가 소수인지 판별하기
    assert(prime_factors > 0);
    if (eratostenes[prime_factors]) cnt++;
    A++;
  }

  cout << cnt << endl;

}