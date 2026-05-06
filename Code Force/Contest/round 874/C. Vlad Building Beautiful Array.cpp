#include <vector>
#include <iostream>
#include <set>
#include <iterator>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef set<int> si;

si s;

void    solve(void){
	int n,tmp;
	cin >> n;
	s.clear();
	REP(i, 1, n){
		cin >> tmp;
		s.insert(tmp);
	}
	si::iterator it = s.begin();
	int f = (*it) % 2;
	for (it = s.begin(); it != s.end(); it++){
		if (*it % 2  != f){
			si::iterator it2;
			for (it2 = s.begin(); it2 != s.end();){
				if (*it > *it2 && (*it - *it2) % 2 == f)
					break ;
				if (++it2 == s.end()){
					cout << "No\n";
					return ;
				}
			}
		}
	}
	cout << "Yes\n";
}

int	main(){
	int	t;
	cin >> t;
	while (t--) solve();
	return (0);
}