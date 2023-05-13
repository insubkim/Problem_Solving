#include <bits/stdc++.h>
//#include <iostream>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int sum,m,tmp;


void    solve(void){
    sum = 0;
    m = INT_MAX;
    REP(i, 0, 6){
        cin >> tmp;
        if (!(tmp % 2)){
            if (m > tmp)
                m = tmp;
            sum += tmp;
        }
    }
    cout << sum << " " << m << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}