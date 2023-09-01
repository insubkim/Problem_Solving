#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(int a, int b) { return a >= b; }

long long solution(vector<int> weights) {
  long long answer = 0;
  sort(weights.begin(), weights.end(), cmp);
  for (int i = 0; i < weights.size(); i++) {
    for (int j = i + 1; j < weights.size(); j++) {
      if (weights[i] == weights[j] || weights[i] * 2 == weights[j] * 3 ||
          weights[i] * 2 == weights[j] * 4 ||
          weights[i] * 3 == weights[j] * 4) {
        answer++;
      }
    }
  }
  return answer;
}
#include <iostream>
int main() {
  vector<int> a = {200, 100, 1000, 1000, 1000, 100};

  long long c = solution(a);
  cout << c << std::endl;
}