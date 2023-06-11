#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int a;
    for (a = 2; a * a < n - 1; a++){
        if (n % a == 1)
            return a;
    }
    return n - 1;
}