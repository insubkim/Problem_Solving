#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

void    solve(void){
    int n,tmp;
    cin >> n;
    int M = n-1;
    REP(i, 1, n){
        cin >> tmp;
        if (tmp > i){
            if (M > tmp - i)
                M = tmp - i;
        }else if (tmp < i){
            if (M < tmp - i)
                M = tmp - i;
        }
    }  
    cout << M << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}