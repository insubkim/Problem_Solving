#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define	PB push_back


using namespace std;

typedef	multiset<int> si;

si s;

int main(){
    int a;
    
    cin >> a;
    while (a > 0){
        s.insert(a % 10);
        a = a / 10;
    }

    si::reverse_iterator it;
    for (it = s.rbegin(); it != s.rend(); it++){
        cout << *it;
    }

}