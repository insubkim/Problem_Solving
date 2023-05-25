#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back
using namespace std;

typedef	vector<int> vi;
typedef	set<int> si;

vi	v;
si s;

void	solve(void){
    int n;
    string a;
    cin >> n >> a;
    int k = 1;
    s.insert(k);
    for (int i = 0; i < (int)a.size(); i++){
        if (a[i] == '<'){
            if (s.upper_bound(k) == s.end()){
                s.insert(k + 1);
                k = k + 1;
            }else{
                k = *s.upper_bound(k);    
            }
        }else{
            int min_max = k;
            si::iterator it;
            for(it = s.begin(); it != s.end(); it++){
                if (*it < k && (*it > min_max || min_max == k)){
                    min_max = *it; 
                }
            }
            if (min_max != k){
                k = min_max;
            }else{
                s.insert(k - 1);
                k = k -1;
            }
        }
    }
    cout << s.size() << endl;
    
    s.clear();
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}