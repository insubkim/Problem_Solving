#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef set<int> si;

si s;

int main(){
    int t,tmp;
    cin >> t;
    while (t--){
        cin >> tmp;
        s.insert(tmp);
    }
    tmp = *(s.begin());
    si::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        t = *iter;    
    }
    tmp = tmp * t;
    cout << tmp << endl;
    return (0);
}