#include <iostream>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    string str;

    while (1) {
        int num = 0;
        getline(cin, str);
        if (str == "#") break ;
        for (auto x : str) {
            if (x == 'a' || x ==  'e' || x ==  'i' ||  x == 'o' || x == 'u' || \
                x == 'A' || x ==  'E' || x ==  'I' ||  x == 'O' || x == 'U' )
                num++;
        }
        cout << num << endl;
    }
    return 0;
}