#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){

    int N,M,tmp;
    int n_len = 1;
    cin >> N >> M;
    tmp = N;
    while (tmp >= 10){
        tmp = tmp / 10;
        n_len++;
    }
    if (n_len > M){
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