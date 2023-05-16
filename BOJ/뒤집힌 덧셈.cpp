#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int rev(int a){
    int tmp = 0;
    while (a > 0){
        tmp = tmp * 10 + a % 10;
        a /= 10;
    }
    return (tmp);
}

int main(){
    int a,b;
    cin >> a >> b;
    a = rev(rev(a) + rev(b));
    cout << a << endl;
    return (0);
}