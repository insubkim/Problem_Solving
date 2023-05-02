#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;
typedef set<int>si;

si s;

int main(){
    int tmp;
    REP(i, 0, 9){
        cin >> tmp;
        s.insert(tmp % 42);        
    }
    cout << s.size() << endl;
}   