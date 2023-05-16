#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    char s[101] = {0,};
    cin >> s;
    char *t = s;
    while (*t++) ;
    cout << (--t - s) << endl;

    return (0);
}