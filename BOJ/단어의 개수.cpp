#include <iostream>
#include <string>

#include <string.h>

using namespace std;

int main() {

    string line;

    getline(cin, line);

    bool start_cnt = true; 
    int vocab_cnt = 0;
    // "    a  a "
    for (auto x: line) {
        if (x == ' ') {
            start_cnt = true;
            continue ;
        }
        if (start_cnt) {
            vocab_cnt++;
        }
        start_cnt = false;
    }

    cout << vocab_cnt << endl;
}