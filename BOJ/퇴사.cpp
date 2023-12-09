#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <iterator>

using namespace std;

int N;

vector<pair<int, int> > TP;

int solve() { 
  stack<int> select_days;

  //0일 선택
  select_days.push(0);

  int max = 0;
  
  while (!select_days.empty()){
    
    int top = select_days.top() + 1;
    select_days.pop();
    
    while (top <= N){
      if (TP[top].first + top <= N + 1){
        select_days.push(top);
        top = top + TP[top].first;
      }
      else  top++;
    }

    stack<int> copy = select_days;
    int sum = 0;
    while(!copy.empty()){
      sum += TP[copy.top()].second;
      copy.pop();
    }
    if (sum > max) max = sum;
  }
  return max; 
}

int main() {
  cin >> N;
  TP.push_back(make_pair(0,0));
  for (int i = 1; i <= N; i++){
    int a,b;
    cin >> a >> b;
    TP.push_back(make_pair(a,b));
  }
  cout << solve() << endl;
  return 0;
}