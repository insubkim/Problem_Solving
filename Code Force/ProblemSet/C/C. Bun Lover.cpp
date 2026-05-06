#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = a; i <= b; i++)
#define PB push_back 

using namespace std;

typedef vector<unsigned long long> vi;

vi v;
vi dp;

// void    solve(void){
//     long unsigned int n,size;

//     cin >> n;
//     if (dp.size() > n){
//         v.PB(dp[n]);
//         return ;
//     }
//     size = dp.size();
//     while (size <= n){
//         dp.PB(dp[size - 1] + size * 2 + 1);
//         size = dp.size();    
//     }
//     v.PB(dp[n]);
// }

void    solve(void){
    unsigned long long n;
    
    cin >> n;
    n = n * n + 2 * n + 2;
    v.PB(n);
}

int main(){
    int t;


    cin >> t;
    while (t--) solve();
    for (auto x : v){
        cout << x << endl;
    }
    return (0);
}