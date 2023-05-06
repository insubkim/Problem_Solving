#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef multiset<int> mi;

mi m;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    m.insert(a);
    m.insert(b);
    m.insert(c);
    multiset<int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++){
        cout << *iter <<endl;
    }
    return (0);
}