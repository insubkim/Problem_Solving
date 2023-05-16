#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    int w[101] = {0,};
    int k[101] = {0,};
    int tmp;
    REP(i, 1, 10){
        cin >> tmp;
        w[tmp]++;
    }
    REP(i, 1, 10){
        cin >> tmp;
        k[tmp]++;
    }
    tmp = 0;
    int cnt = 3;
    for (int i = 100; i >= 0; i--){
        if (w[i] > 0){
            tmp += w[i] < cnt ? i * w[i] : i * cnt;  
            cnt -= w[i];
        }
        if (cnt <= 0)
            break ;
    }
    int sum = tmp;
    tmp = 0;
    cnt = 3;
    for (int i = 100; i >= 0; i--){
        if (k[i] > 0){
            tmp += k[i] < cnt ? i * k[i] : i * cnt;  
            cnt -= k[i];
        }
        if (cnt <= 0)
            break ;
    }
    cout << sum << " " << tmp <<endl;
    return (0);
}