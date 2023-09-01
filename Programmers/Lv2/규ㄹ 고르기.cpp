#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second <= b.second;
  }
};

int solution(int k, vector<int> tangerine) {
  int answer = 0;

  map<int, int> arr;
  for (auto x : tangerine) {
    arr[x]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  for (map<int, int>::iterator x = arr.begin(); x != arr.end(); x++) {
    pq.push(make_pair(x->first, x->second));
  }
  int val;
  while (k > 0) {
    val = pq.top().second;
    pq.pop();
    k -= val;
    answer++;
  }
  return answer;
}

int main() {
  vector<int> c = {1, 3, 2, 5, 4, 5, 2, 3};
  int a = solution(6, c);
  std::cout << a << std::endl;
  return 0;
}