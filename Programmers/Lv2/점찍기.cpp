#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    int dk = d / k;
    int jStart = 0;
    for (long long i = 0; i <= dk; i++){//y좌표
        //x = 0 , 0 ~ d / k
        //x = 1 , d / k - j ~ 0
        //x = 2 , d / k - j ~ 0
        //...
        for (long long j = jStart; j <= dk; j++){
            if (pow(i * k, 2) + pow(dk * k - j * k, 2) <= pow(d, 2)){
                answer += dk - j + 1;
                jStart = j;
                break ;
            }
        }
    }
    return answer;
}