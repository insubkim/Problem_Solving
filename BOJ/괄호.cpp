#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int N;

    cin >> N;

    while (N--) {
        string line;
        cin >> line;

        int braclet = 0;
        for (auto x : line) {
            if (x == '(') {
                braclet++;
            } else if (x == ')') {
                braclet--;
            }
            if (braclet < 0) {
                break ;
            }
        }
        if (braclet != 0) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}