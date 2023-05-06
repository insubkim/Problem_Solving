#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef set<int> si;

si s;

int main(){
    s.insert(10);
    s.insert(20);
    s.insert(30);

    si::iterator iter;
    iter = s.lower_bound(21);
    int a = *iter;
    iter = s.upper_bound(21);
    int b = *iter;

    cout <<"lower_bound =" << a << endl;
    cout <<"upper_bound =" << b << endl;
    return (0);
}