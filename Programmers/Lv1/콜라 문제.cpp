#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int c = 0;
    while (n >= a){
        c += (n / a) * b;
        n = (n / a) * b + n % a;
    }
    return c;
}