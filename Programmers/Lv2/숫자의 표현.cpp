#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* 
 * 첫째항  a 
 * 마지막항 b
 * 항의갯수 x
 * 라고 하였을때, a ~ b 의 합은
 * (x) * (a + b) 이다.
 * x 는 b - a + 1 로 다시 정리할 수 있다.
 * 
 * (b - a + 1) * (a + b) = n 이다.
 * b 에 대해서 정리하면
 * b * (b + 1) = a * (a + 1) + n 으로 나타낼수있다.
 * 따라서 b * (b + 1) 의 가까운 제곱근을 값을 구해주고 
 * 확인해주면된다.
 */
bool findContinuousSequence(int start, int sum) {
  int end = floor(sqrt(2 * sum + start * start - start));
  return end * (end + 1) == 2 * sum + start * start - start;
}

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n / 2; i++) {
      if (findContinuousSequence(i, n))
        answer++;
    }
    return answer + 1; //마지막항은 예외처리, 무조건 성립 n == n
}