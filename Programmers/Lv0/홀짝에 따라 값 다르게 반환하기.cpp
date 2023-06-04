#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (n % 2 == 0){
        int sum = 0;
        for (int i = 2; i <= n; i += 2){
            sum += i * i;
        }
        return sum;
    }else{
        return (n / 2) * (n / 2 + 1) + 1 + (n / 2);
    }
}