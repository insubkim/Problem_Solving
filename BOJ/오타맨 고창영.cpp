#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<char> vc;

vc v;

void    solve(void){
    int n;
    char c[81] ={0,};
    cin >> n >> c;
    int i = 0;
    while (c[i]){
        if (--n == 0)
            ;
        else
            v.push_back(c[i]); 
        i++;
    }
    v.push_back('\n');
}

int main()
{
    int t;
    cin >> t;
    while (t--) solve();
    for (auto x : v){
        cout << x;
    }
    return (0);
}
