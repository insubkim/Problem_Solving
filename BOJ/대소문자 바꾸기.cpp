#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int main(){
    char s[101] = {0,};
    cin >> s;
    REP(i, 0, (int)strlen(s) - 1){
        if (s[i] <= 'Z')
            cout << (char)(s[i] + 32);
        else 
            cout << (char)(s[i] - 32);
    }
    cout << endl;
    return (0);
}