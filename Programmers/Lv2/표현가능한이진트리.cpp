#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long next_dummy_tree(int height) {
  long long dummy_tree = 1;
  // 왼쪽 자식 노드 수 만큼 왼쪽 시프트
  // 1 층이면 자식 2^0 -1
  // 2 층이면 자식 2^1 -1
  // 3 층이면 자식 2^2 -1
  dummy_tree = dummy_tree << (int)pow(2, height - 1) - 1;
  return dummy_tree;
}

long long next_p_tree(int height) {
  long long p_tree = 1;
  // 2 층이면 자식 111
  // 3 층이면 자식 1111 11 1 11 1111
  for (int i = 1; i <= 2 * (int)pow(2, height - 1) - 1; i++) {
    p_tree = p_tree << 1;
    p_tree = p_tree & 0b1;
  }
  return p_tree;
}

int solve(long long n) {
  int height = 1;
  long long p_tree = 0b1;
  long long dummy_tree;
  while (n >= p_tree) {
    if (p_tree == n) {
      return true;
    }
    dummy_tree = next_dummy_tree(height);
    p_tree = next_p_tree(height);
    if (dummy_tree == (n & dummy_tree) && n < p_tree) return true;
    height++;
  }
  return false;
}

vector<int> solution(vector<long long> numbers) {
  vector<int> answer;
  for (auto x : numbers) {
    answer.push_back(solve(x));
  }
  return answer;
}
/*
    1
    * *

    1
    1 1
    * * * *

    solve(){
    degree = 1;
    while (tree <= A)
        tree = next(degree);
        if (A == tree)
            return (true);
        if (A & getDummyTree(degree) == getDummyTree(degree))
            return (true);
        degree++;
    return (false);
    }
*/

#include <iostream>
int main() {
  vector<long long> a = {7};
  solution(a);
}