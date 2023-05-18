#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){

    int N,M;
    cin >> N >> M;
    if (N > M){
        REP(i, 1, M){
            cout << N;
        }
    }else{
        REP(i, 1, N){
            cout << N;
        }
    }
    cout << endl;
    return (0);
}