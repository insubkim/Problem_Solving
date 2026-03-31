#include <iostream>

using namespace std;

int numbers[10001];

void    cal_dn(int n) {
    if (numbers[n]) {
        return ;
    }

    int d_n = n;
    while (1) {
        // d(n) 계산
        // d(n) => n + n 의 각 자릿수
        int ori_d_n = d_n;
        while (ori_d_n) {
            int ones_place = ori_d_n % 10;
            d_n += ones_place;
            
            ori_d_n /= 10;
        }

        if (d_n <= 10000)
            numbers[d_n] = 1;
        else
            break;
    } 

}

int main() {
    // n 1 부터 9999 까지 d(n) 계산
    // 10000 보다 크면 중단
    // 계산값은 numbers 에 저장
    // 이미 계산되었으면 skip

    for (int n = 1; n <= 9999; n++) {
        cal_dn(n);
    }

    for (int n = 1; n <= 10000; n++) {
        if (numbers[n]) {
            continue ;
        }

        cout << n << endl;
    }

    return 0;
}