#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

bool  isSignSame(char first, char second) {
  // - -
  // digit digit
  return \
        (first == second) ||
        (isdigit(first) && isdigit(second));
}

/*
 * return true if first < bigger
 */
bool  isFirstSmaller(const string& first, const string& second) {
  //check sign
  if (!isSignSame(first[0], second[0])) {
    return first[0] == '-' ? true : false;
  }

  //check length
  if (first.size() != second.size()) {
    return first[0] == '-' ? first.size() > second.size() : first.size() < second.size();
  }

  //compare
  return first[0] == '-' ? first > second : first < second;
}

string solution(string s) {
  stringstream  ss(s);
  string        min;
  string        max;

  getline(ss, min, ' ');
  getline(ss, max, ' ');
  if (isFirstSmaller(max, min))  swap(min, max);
  

  string tmp;
  while (getline(ss, tmp, ' ') && !ss.fail()) {
    if (isFirstSmaller(max, tmp))  max = tmp;
    if (isFirstSmaller(tmp, min))  min = tmp;
  }

  string  answer = min + ' ' + max;
  return answer;
}

#include <iostream>
int main() {
  string test;
  getline(cin, test);
  string answer = solution(test);
  
  stringstream ss(answer);
  long long min, max;
  ss >> min >> max;
  if (min < max)
    return 0;
  cout << test << endl;
  cout << "solution : " << solution(test) << endl;
  return 1;
}