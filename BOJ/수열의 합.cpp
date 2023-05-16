#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    int N,L,tmp;
    cin >> N >> L;
    while (L <= 100){
        tmp = ((L - 1) * (L)) / 2 -L;
        for (int i = 0; ; i++){
            tmp += L;
            if (N == tmp){
                REP(j, i, i + L - 1){
                    cout << j << " ";
                }
                cout << endl;
                return 0;
            }else if (N < tmp)
                break ;
        }
        L++;
    }
    cout << -1 << endl;
    return 0;
}