#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

vi v;
vi dp;

void    solve(int n, int k){
    //분산 = 제곱의 평균 - 평균의 제곱
    long double min = -2;
    int sum;
    long long pow_sum;
    long long avr;
    REP(i, 0, n-k){
        sum = 0;
        pow_sum = 0;
        REP (j, i, n-1){
            sum += v[j];
            pow_sum += v[j] * v[j];
            if (min < -1 && j - i + 1== k){
                avr = ((long double)sum) / (j - i + 1.0);
                min = ((long double)pow_sum) / (j - i + 1.0) - avr * avr;
            }else if (j - i + 1 >= k){
                avr = ((long double)sum) / (j - i + 1.0);
                    cout << i << " " << j << " " << sum << " " << avr <<endl;
                if (min > ((long double)pow_sum) / (j - i + 1.0) - avr * avr){
                    min = ((long double)pow_sum) / (j - i + 1.0) - avr * avr; 
                }
            }
        }
    }
    printf("%Lf\n", sqrt(min));
}
/*
10 3
1 4 1 5 9 2 6 5 3 5
*/
int main(){
    int n,k;

    cin >> n >> k;
    int tmp;
    REP(i, 1, n){
        cin >>tmp;
        v.PB(tmp);
    }
    solve(n, k);
    return (0);
}