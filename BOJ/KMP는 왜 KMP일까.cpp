#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int main(){
    char c[101] = {0,};
    cin >> c;
    REP(i, 0, (int)strlen(c)){
        if ('A' <= c[i] && c[i] <= 'Z')
            cout << c[i];
    }
    cout << endl;
    return (0);
}