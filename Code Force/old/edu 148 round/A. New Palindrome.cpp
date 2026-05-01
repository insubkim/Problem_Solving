#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back
using namespace std;

typedef	vector<int> vi;

vi	v;

void	solve(void){
	char	s[51];
	cin >> s;
	int	len = strlen(s);
	char c = s[0];
	REP(i, 1, len / 2 -1){
		if (s[i] != c){
			v.PB(1);
			return ;
		}
	}
	v.PB(0);
}

void	printv(void){
	REP(i, 0, v.size()-1){
		if (v[i]){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}

int	main(){
	int	t;
	cin >> t;
	while (t--)	solve();
	printv();
	return (0);
}