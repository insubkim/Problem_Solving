#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    int N,L,a,tmp;
    cin >> N >> L;
    while (L <= 100){
        tmp = ((L - 1) * (L)) / 2;
        if ((N - tmp) % 4 == 0)
        {
            a = (N - tmp) / 4;
            if (N == 4 * a + tmp){
            REP(i, 1, L){
                cout << a++ << " ";
            }
            cout << endl;
            return 0;
            }
        }
        L++;
    }
    cout << -1 << endl;
    return 0;
}