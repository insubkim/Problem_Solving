#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
  int answer = 0;
  while (storey) {
    if (storey % 10 >= 5) {
      answer += 10 - storey % 10;
      storey /= 10;
      storey++;
    } else {
      answer += storey % 10;
      storey /= 10;
    }
  }
  return answer;
}