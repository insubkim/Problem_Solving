#include <iostream>
#include <string>

using namespace std;

int main() {
  double  rate_board[6] = {4.0, 3.0, 2.0, 1.0, 0.0, 0.0};
  double  sum_credit_mul_rate = 0;
  double  sum_credit = 0;
  for (int i = 1; i <= 20; i++) {
    double  rate;
    double  credit;
    string in;
    cin >> in >> credit;
    cin >> in;

    if (in[0] == 'P') continue;
    rate = rate_board[in[0] - 'A'];
    rate += in[1] == '+' ? 0.5 : 0;

    sum_credit_mul_rate += credit * rate;
    sum_credit += credit;
  }
  cout << sum_credit_mul_rate / sum_credit << endl; 
}