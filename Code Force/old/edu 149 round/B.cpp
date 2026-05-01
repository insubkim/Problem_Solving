#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back
using namespace std;

typedef	vector<int> vi;
typedef	set<int> si;

vi	v;

void	solve(void){
    int n;
    string s;
    cin >> n >> s;
    int k = 1;
    v.PB(k);
    k = 0;
    for(long unsigned int i = 0; i < s.size(); i++){
        if (s[i] == '>'){
            if (k == 0){
                v.PB(v[k] - 1);
                sort(v.begin(), v.end());
            }else{
                k--;
            }
        }else{
            if (k == (int)v.size() - 1){
                v.PB(v[k] + 1);
                sort(v.begin(), v.end());
                k++;
            }else{
                k++;
            }
        }
    }
    cout << v.size() << endl;
    v.clear();
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}