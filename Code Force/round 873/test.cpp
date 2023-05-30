//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

void    solve(void){
    int n,tmp;
    cin >> n;
    vi v;
	REP(i, 1, n){
        cin >> tmp;
        v.PB(tmp);
    }  
	int	m = n;
	REP(i, 1, n){
		while (1){
			if (v[i - 1] % m == i % m){
				break ;
			}
			else
				m--;
		}
	}
    cout << m << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}