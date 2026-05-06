#include <vector>
#include <string>
#include <set>
#include <iostream>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef set<pair<char, char>> sp;
typedef pair<char, char> pcc;


sp s;

void    solve(void){
	int	n;
	char c[51] ={0,};
	cin >> n >> c;
	pcc p = make_pair(c[0], c[1]);
	s.insert(p);
	REP(i, 1, n - 2){
		pcc p1 = make_pair(c[i], c[i+1]);
		s.insert(p1);
	}
	cout << s.size() << endl;
	s.clear();
}

int	main(){
	int	t;
	cin >> t;
	while (t--) solve();
	return (0);
}