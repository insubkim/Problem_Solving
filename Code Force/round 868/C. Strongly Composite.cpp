#include <bits/stdc++.h>

#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PB push_back


using namespace std;

typedef	vector<int> vi;
typedef multiset<int> mi;

void	search(void)
{
	int	n;
	vi	a;

	cin >> n;
	REP(i, 1, n){
		int	j;
		cin >>j;
		//j 소인수 분해하여 mi에 add
		factorization(j);
	}
	//소수와 s.p의 갯수 카운트
	//s.p < 소수 면 k 구하고 출력
	//multiset의 각 원소 갯수 / 2

}

int	main()
{
	int	t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdin);
	#endif
	cin >>t;
	while (t--) search();
	return (0);
}