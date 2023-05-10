#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define	PB push_back


using namespace std;

typedef	set<int> si;
typedef	vector<int> vi;

vi v;

void    solve(void){
    si  s;
    int tmp;
    REP(i, 1, 10){
        cin >> tmp;
        s.insert(tmp);
    }
    int i = 1;
    for (auto x : s){
        if (i == 8){
            v.push_back(x);
            return ;
        }
        i++;
    }
}



int main(){
    int t;
    cin >> t;
    while (t--) solve();

    for(auto x : v){
        cout << x << endl;
    }

}