#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string tmp;
    string s;
    while (1)
    {
        getline(cin, tmp);
        if (tmp != "END")
            reverse(tmp.begin(), tmp.end());
        if (tmp == "END")
            break ;
        tmp += '\n';
        s += tmp;
    }
    cout << s;
    return 0;
}