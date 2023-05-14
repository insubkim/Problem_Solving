#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

vi  v;

void    solve(void){
    int n,tmp;
    cin >> n;
    if (n % 2){
        REP(i, 1, n){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    tmp = n - ((((n) * (n + 1)) / 2 - 1) % n);
    cout << tmp << " ";
    REP(i, 2, n){
        cout << i << " ";
    }
    cout << endl;
    
}

int main(){
    int t;
    cin >>t;
    while (t--) solve();
    return (0);
}