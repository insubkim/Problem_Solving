#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
  vector<int> answer(prices.size(), -1);
  stack<int> s;
  s.push(0);
  for (int i = 1; i < prices.size(); i++) {
    while (!s.empty() && prices[i] < prices[s.top()]) {
      answer[s.top()] = i - s.top();
      s.pop();
    }
    s.push(i);
  }
  for (int i = 0; i < answer.size(); i++) {
    if (answer[i] == -1) answer[i] = answer.size() - 1 - i;
  }
  return answer;
}