#include <bits/stdc++.h>
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;

typedef vector<int> vi;

void    solve(void){
    int x1,x2,y1,y2,r1,r2,tmp;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (x1 == x2 && y1 == y2){
        if (r1 == 0 && r2 == 0)
            cout << 1 << endl;
        else if (r1 == r2)
            cout << -1 << endl;
        else
            cout << 0 << endl;
        return ;
    }
    int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    if (d == r1 + r2)
        cout << 1 << endl;
    else if (d > r1 + r2){
        cout << 0 << endl;
    }else{
        tmp = r1;
        if (r1 > r2){
            r1 = r2;
            r2 = tmp;
        }
        if (r2 - r1  )
    }
}

int main()
{
    int t;
    while (t--) solve();
    return 0;
}