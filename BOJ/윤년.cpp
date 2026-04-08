#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_leap_year(int y) {
    //윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.
    return y % 4 == 0 
        && (y % 100 != 0 || y % 400 == 0); 
}

int main() {
    int N;
    cin >> N;

    cout << (is_leap_year(N) ? 1 : 0) << endl;
    return 0;
}