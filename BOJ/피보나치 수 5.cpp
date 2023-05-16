#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    long long a = 0;
    long long b = 1;
    long long n,tmp;
    
    cin >> n;
    REP(i, 2, n){
        tmp = b;
        b = a + b;
        a = tmp;
    }
    if (n == 0)
        cout << 0 << endl;
    else if (n == 1)
        cout << 1 << endl;
    else
        cout << b << endl;
    return 0;
}