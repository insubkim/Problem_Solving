#include <bits/stdc++.h>
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;

multiset<int> s;

int main(){
    int n, t;
    cin >> n;
    while (n--){
        cin >> t;
        s.insert(t);
    }
    int v;
    cin >> v;
    cout << s.count(v) <<endl;
}