#include <set>
#include <vector>
#include <iostream>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back
using namespace std;

typedef set<int> si;
typedef	vector<int> vi;

vi	v;
si	s;

void	printv(void){
	vi::iterator it;
	for (it = v.begin(); it != v.end(); it++){
		cout << *it << endl;
	}
}

void	solve(void){
	int	n,a;
	cin >> n;
	REP(i, 1, 4){
		s.insert(n % 10);
		a = n % 10;
		n = n / 10;
	}
	if (s.size() == 1){
		v.PB(-1);
	}else if (s.size() == 4){
		v.PB(4);
	}else if (s.size() == 3){
		v.PB(4);
	}else{
		if (s.count(a) == 2){
			v.PB(4);
		}else{
			v.PB(6);
		}
	}
	s.clear();
	/*
		2일때,
		1112

		1122

		1222
	
	*/


}

int	main(){
	int	t;
	cin >> t;
	while (t--)	solve();
	printv();
	return (0);
}