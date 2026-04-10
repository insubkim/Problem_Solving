#include <iostream>

using namespace std;

int div_n(int n, int div) {
    int cnt = 0;

    while (n % div == 0) {
        n /= div;
        cnt++;
    }
    
    return cnt;
}

int main(void) {
    int N;

    cin >> N;

    int zeros = 0;
    int twos = 0;
    int fives = 0;

    for (int i = 1; i <= N; i++) {
        twos += div_n(i, 2);
        fives += div_n(i, 5);
    }

    zeros = twos < fives ? twos : fives;
    cout << zeros << endl;
}