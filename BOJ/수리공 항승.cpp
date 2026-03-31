#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // 파이프 상태. 새면 상태 1 
  vector<int> pipe;

  // 새는 곳 갯수, 테이프 길이
  int N,L;
  cin >> N >> L;

  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    pipe.push_back(tmp);
  }

  sort(pipe.begin(), pipe.end());
  

  int tape_cnt = 0;
  int last_taped = 0;

  // 새는 곳 확인
  for (auto &x: pipe) {
    // 테이프 감겼는지 확인    
    if (x <= last_taped) 
      continue;
    // 테이프 감기  
    last_taped = x + L - 1;
    tape_cnt++;
  }

  cout << tape_cnt << endl;

  return 0;
}