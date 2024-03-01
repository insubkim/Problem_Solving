#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

// void  solve(int a, int b) {
//   int min_measure = 0;

//   for (int i = 2; i <= a;) {
//     if (a % i == 0) {
//       min_measure += i;
//       a /= i;
//     }
//     else i++;
//   }

//   if (b < min_measure) cout << "no" << endl;
//   else cout << "yes" << endl; <<<<< -1 됨으로 다됨
// }

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << "yes" << endl;
  } 
}