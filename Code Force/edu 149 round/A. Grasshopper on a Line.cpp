#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back
using namespace std;

typedef	vector<int> vi;

vi	v;

void	solve(void){
    int x,k;
    cin >> x >> k;
    if (x % k == 0){
        cout << 2 << endl;
        cout << x - 1 <<  " " << 1 << endl;
    }else{
        cout << 1 << endl;
        cout << x << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}