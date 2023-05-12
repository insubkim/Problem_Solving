#include <set>
#include <vector>
#include <iostream>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define	PB push_back

using namespace std;

typedef	set<int> si;
typedef	vector<int> vi;

si	s;
vi	v;

void	solve(void)
{
	int	n,sit,tmp;
	cin >> n >> sit;
	REP(i, 1, n){
		cin >> tmp;
		s.insert(tmp);
	}
	tmp = n - s.size();
	v.PB(tmp);
	s.clear();
}

void	printv(void){
	vi::iterator it;
	for (it = v.begin(); it != v.end(); it++){
		cout << *it << endl;
	}
}

int	main(){
	int	t;
	cin >> t;
	while (t--) solve();
	printv();
	return (0);
}