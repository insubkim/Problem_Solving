#include <iostream>

using namespace std;

int main() {
    // +, - 숫자가 온다.
    // 1. - 숫자가 오면 뒤따르는 숫자들은 전부 마이너스가 된다.
    // 2. 각 숫자를 받을때마다 1원칙에 따라 더한다.
    // 3. 첫 숫자는 부호가 없다.
    
    int min_sum;
    cin >> min_sum;

    bool minus_flag = false;
    char sign;
    int n;
    while (cin >> sign >> n) {
        
        if (minus_flag) {
            min_sum -= n;
            continue ;
        }

        if (sign == '-') {
            min_sum -= n;
            minus_flag = true;
        } else {
            min_sum += n;
        }

    }

    cout << min_sum << endl;

    return 0;
}