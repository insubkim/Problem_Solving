#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
  if (a[0] < b[0]) return true;
  if (a[0] == b[0]) return a[1] < b[1];
  return false;
}

int solution(vector<vector<int>> lines) {
  int answer = 0;
  sort(lines.begin(), lines.end(), cmp);
  int start = lines[0][0];
  int end = lines[0][1];
  for (size_t i = 1; i < lines.size(); i++) {
    if (lines[i][1] > start && lines[i][0] < end) {
      answer += (lines[i][1] < end ? lines[i][1] : end) -
                (start > lines[i][0] ? start : lines[i][0]);
      start = lines[i][1] < end ? lines[i][1] : end;
      end = lines[i][1] > end ? lines[i][1] : end;
    } else {
      start = lines[i][0];
      end = lines[i][1];
    }
  }
  return answer;
}