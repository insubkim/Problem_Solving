#include <iostream>
#include <string>

#include <string.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    while (T--) {

        int n;
        string line;

        cin >> n >> line;

        for (auto x: line) {
            for (int i = 0; i < n; i++) {
                cout << x;
            }
        }
        cout << '\n';
    }
}