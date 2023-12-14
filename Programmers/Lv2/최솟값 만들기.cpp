#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
  int answer = 0;
  
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  vector<int>::iterator         it_A  = A.begin();
  vector<int>::reverse_iterator rit_B = B.rbegin();

  while (it_A != A.end()) {
    answer += *it_A++ * *rit_B+;
  }

  return answer;
}
