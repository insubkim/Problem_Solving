#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

vi v1;
vi v2;


void    solve(void){
    int n, tmp;
    cin >> n;
    REP(i, 1, n){
        cin >> tmp;
        v1.PB(tmp);
    }
    sort(v1.begin(), v1.end());
    REP(i, 1, n){
        cin >> tmp;
        v2.PB(tmp);
    }
    sort(v2.begin(), v2.end());
    unsigned long long a = 1;
    REP(i, 0, n-1){
        int j = 0;
        while (j < n){
            if (j >= i){
                cout << 0 << endl;
                return ;
            }
            if (v1[j] > v2[i]){
                a *= n - j -(n - i - 1);
                break ;
            }
            j++;
        }
    }
    cout << a << endl;
    v1.clear();
    
    v2.clear();
}


int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}