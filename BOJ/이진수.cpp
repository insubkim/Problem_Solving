#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

vi v;


void search(){
    int n;

    cin >> n;
    REP(i , 0, 31){
        if (n >> i & 1){
            v.push_back(i);
        }
    }
    v.push_back(-1);

}

int main(){
    int t;
    cin >> t;
    while (t--) search();
    for (auto x : v){
        if (x != -1)
            cout << x << " ";
        else
            cout << endl;
    }
    return (0);
}