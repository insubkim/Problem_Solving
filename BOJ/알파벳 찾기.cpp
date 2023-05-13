//#include <bits/stdc++.h>
#include <iostream>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    int    a[26];
    fill_n(a, 26, -1);
    char    s[101] = {0,};
    cin >> s;
    int i = 0;
    while (s[i]){
        if (a[s[i] - 97] == -1)
            a[s[i] - 97] = i;
        i++;
    }
    REP(j, 0, 25){
        cout << a[j] << " ";
    }
    cout << endl;
    return (0);
}