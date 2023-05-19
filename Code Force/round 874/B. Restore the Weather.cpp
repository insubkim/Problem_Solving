#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef set<pair<int, int>> sp;
typedef pair<char, char> pcc;
typedef vector<int> vi;
typedef set<int> si;



void    solve(void){
	int	n,k,tmp;
	cin >> n >> k;
	vi a;
	sp aa;
	REP(i, 1, n){
		cin >> tmp;
		a.PB(tmp);
		aa.insert(make_pair(tmp, i));
	}
	sp b;
	sp::iterator it = aa.begin();
	REP(i, 1, n){
		cin >> tmp;
		b.insert(make_pair(tmp, (*it).second));
		it++;
	}
	int	arr[n];
	for (it = begin(); it != b.end(); it++){
		arr[(*it).second - 1] = (*it).first;
	}
	REP(i, 0, n - 1){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int	main(){
	int	t;
	cin >> t;
	while (t--) solve();
	return (0);
}