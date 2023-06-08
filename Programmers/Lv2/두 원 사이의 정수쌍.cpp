#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long a = 0;
    int tmp = r1;
    if (r1 > r2){
        r1 = r2;
        r2 = tmp;
    }
    //1 ~ r2
    long long y1, y2;
    double y1_d, y2_d;
    for (int x = 1; x <= r2; x++){
        y1 = (((long long)r1 * r1) - ((long long)x * x));
        if (y1 < 0)
            y1 = 0;
        y2 = (((long long)r2 * r2) - ((long long)x * x));
        y1_d = sqrt(y1);
        y2_d = sqrt(y2);
        if ((int)y1_d + 1 <= (int)y2_d){
            a += (int)y2_d - (int)y1_d;
        }
        if (((int)y1_d) * ((int)y1_d) >= y1){
            a++;
        }
    }
    return a * 4;
}

int main(){
    long long k = solution(2,3);
    return 1;
}

