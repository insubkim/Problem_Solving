#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

int main(){
    int n,k,tmp;
    cin >> n >> k;
    int v[11] = {0,};
    REP(i, 1, n){
        cin >> tmp;
        v[i] = tmp;
    }
    tmp = 0;
    for(int i = n; i >= 1; i--){
        tmp += k / v[i];
        k = k % v[i];
    }
    cout << tmp << endl;
    return (0); 
}