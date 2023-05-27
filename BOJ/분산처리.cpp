#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

void    solve(void){
    int n1,n2;
    cin >> n1 >> n2;
    int t  = 1;
    n1 = n1 % 10; 
    while (n2--){
        t = (t * n1) % 10;
    }   
    cout << t << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}