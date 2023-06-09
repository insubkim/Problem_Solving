#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int ft_pow(int n1, int n2){
    int t = 1;
    REP(i, 1, n2){
        t = t * n1;
    }
    return (t);
}

void    solve(void){
    int n1,n2;
    cin >> n1 >> n2;
    if (n1 == 10){
        cout << 10 << endl;
    }else{
        n2 = n2 % 4;
        if (n2 == 0)
            n2 = 4;
        cout << ft_pow(n1, n2) % 10 << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}