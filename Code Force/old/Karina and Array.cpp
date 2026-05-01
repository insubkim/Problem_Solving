#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = a; i <= b; i++)
#define PB push_back 

using namespace std;

typedef vector<unsigned long long> vi;

vi v1;
vi v2;

void    solve(void){
    long long tmp;
    long long n,p1,p2,m1,m2;
    cin >> n;
    p1 = -1;
    p2 = -1;
    m1 = 1;
    m2 = 1;
    REP(i, 1, n){
        cin >> tmp;
        if (tmp >= 0){
            if (p1 == -1){
                p1 = tmp;
            }else if (p2 == -1){
                p2 = tmp;
                if (p2 > p1){
                    p2 = p1;
                    p1 = tmp;
                }
            }else{
                if (tmp > p1){
                    p2 = p1;
                    p1 = tmp;
                }else if (tmp > p2){
                    p2 = tmp;
                }
            }
        }else{
           if (m1 == 1){
                m1 = tmp;
            }else if (m2 == 1){
                m2 = tmp;
                if (m2 < m1){
                    m2 = m1;
                    m1 = tmp;
                }
            }else{
                if (tmp < m1){
                    m2 = m1;
                    m1 = tmp;
                }else if (tmp < m2){
                    m2 = tmp;
                }
            }
        }
        
    }
    long long out = 0;
    if (p1 != -1 && p2 != -1){
        out = p1 * p2;
    }
    if (m1 != 1 && m2 != 1){
        tmp = m1 * m2;
        if (p1 != -1 && p2 != -1){
            if (out < tmp)
                out = tmp;
        }else{
            out = tmp;
        }
    }
    n = -1;
    if (m1 != 1 && p1 != -1){
        n = m1 * p1;
        if ((p1 != -1 && p2 != -1) || (m1 != 1 && m2 != 1)){
            if (out < n)
                out = n;
        }else{
            out = n;
        }
    }
    cout << out << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}