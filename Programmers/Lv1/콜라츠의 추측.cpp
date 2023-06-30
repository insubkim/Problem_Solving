#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long num = n;
    if (n < 0)
            return -1;
    if (num == 1)
        return 0;
    int i = 0;
    while (i < 500){
        i++;
        if (num % 2 == 0){
            num /= 2;
            if (num == 1)
                return i;
        }else{
            num *= 3;
            num++;
        }
    }
    return -1;
}