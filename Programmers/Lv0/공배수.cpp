#include <string>
#include <vector>

using namespace std;

int solution(int nu, int n, int m) {
    return nu % n == 0 && nu % m == 0;
}