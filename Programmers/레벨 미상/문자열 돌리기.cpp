#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (auto x : str){
        cout << x << endl;
    }
    return 0;
}