#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef set<int> si;

si s;

int main(){
    s.insert(10);
    s.insert(20);
    
    si::iterator iter;
    iter = s.lower_bound(30);
    int a = *iter;
    iter = s.upper_bound(1);
    int b = *iter;

    cout <<"lower 30 =" << a << endl;
    cout <<"upper 1=" << b << endl;
    return (0);
}