#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
  vector<int> answer(numbers.size(), -1);
  stack<pair<int, int>> nums;

  for (int i = 0; i < numbers.size(); i++) {
    while (!nums.empty()) {
      if (nums.top().first < numbers[i]) {
        answer[nums.top().second] = numbers[i];
        nums.pop();
      } else {
        break;
      }
    }
    nums.push(make_pair(numbers[i], i));
  }
  return answer;
}

int main() {
  vector<int> x = {2, 3, 3, 5};
  vector<int> a = solution(x);
  for (auto s : a) std::cout << s << std::endl;
  return 0;
}