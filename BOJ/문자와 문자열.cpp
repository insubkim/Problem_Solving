#include <iostream>
#include <string>

#include <string.h>

using namespace std;

int main() {
    string line;
    int idx;

    cin >> line;
    cin >> idx;

    cout << line[idx - 1] << endl;
}