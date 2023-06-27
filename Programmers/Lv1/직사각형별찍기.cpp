#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    string s(a, '*');
    while (b--)
        cout << s << "\n";
    return 0;
}