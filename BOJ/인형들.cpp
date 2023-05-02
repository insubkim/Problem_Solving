#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

vi v;
vi dp;

void    solve(int n, int k){
    long double min = -2;
    long double t;
    long double avr;
    int sum;
    REP(i, 0, n-k){
        sum = 0;
        REP (j, i, n-1){
            sum += v[j];
            if (min < -1 && j == i+k-1){
                t = 0;
                avr = (long double)sum / (j - i + 1);
                REP (l, i, j){
                    t += pow(((long double)v[l] - avr), 2);
                }
                min =  t / (j - i + 1);
            }else if (j >= i+k-1){
                t = 0;
                avr = (long double)sum / (j - i + 1);
                REP (l, i, j){
                    t += pow(((long double)v[l] - avr), 2);
                }
                if (min > t / (j - i + 1)){
                    min = t / (j - i + 1);
                }
            }
        }
    }
    //cout.precision(6);
    //cout << sqrtl(min) << endl;
    printf("%Lf\n", sqrt(min));
}

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