#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int deleteZero(string &s) {
  size_t zeroCount = count(s.begin(), s.end(), '0');
  s.erase(remove(s.begin(), s.end(), '0'), s.end());
  return zeroCount;
}

void  binaryRepresentation(string& s) {
  s = std::bitset<64>(s.size()).to_string();
  bool flag = true;
  s.erase(remove_if(s.begin(), s.end(), [&flag] (char c) -> bool {
    if (c == '1') flag = false;
    return flag && c == '0' ? true : false;
  }), s.end());
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while (s != "1") {
      answer[0]++;
      answer[1] += deleteZero(s);
      binaryRepresentation(s);
    }
    return answer;
}