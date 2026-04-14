#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long A, B;

int min_round;

void    solve(unsigned long long A, int round) {
    if (A == B) {
        if (min_round == -1 || round < min_round) {
            min_round = round;
            return ;
        }
    }

    if (A > B) {
        return ;
    }

    solve(A * 2, round + 1);
    solve(A * 10 + 1, round + 1);

}

int main() {
    cin >> A >> B;

    min_round = -1;
    solve(A, 0);
    
    if (min_round != -1) {
        min_round++;
    }

    cout << min_round << endl;

    return 0;
}