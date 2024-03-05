#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
  int N;
  cin >> N;

  int dasom;
  cin >> dasom;
  int money_dasom = dasom;

  priority_queue<int> q;
  for (int i = 0; i < N - 1; i++) {
    int tmp;
    cin >> tmp;
    q.push(tmp);
  }
  
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }

  while (q.top() >= money_dasom) {
    int tmp = q.top();
    q.pop();
    q.push(tmp - 1);
    money_dasom++;
  }

  cout << money_dasom - dasom << endl;
}