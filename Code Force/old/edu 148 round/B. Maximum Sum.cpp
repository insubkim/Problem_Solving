#include <bits/stdc++.h>
// #include <set>
// #include <vector>
// #include <iostream>
// #include <iterator>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef	vector<unsigned long long> vi;
typedef	set<unsigned long long> si;

vi	v;
si	s;

void	search(void){
	int	n,op;
	unsigned long long tmp;
	
	unsigned long long sum = 0;
	cin >> n >> op;
	REP(i, 1, n){
		cin >> tmp;
		sum += tmp;
		s.insert(tmp);
	}
	unsigned long long min = 0;
	//mmmmmm	구하기
	si::reverse_iterator rit = s.rbegin();
	si::iterator  find_it;
	REP(M, 1, op){
		min += *rit;
		if (M == op)
			find_it = s.find(*rit);
		rit++;
	}
	si::iterator it = s.begin();
	tmp = min;
	REP(i, 1, op){
		tmp += *it++;
		tmp += *it++;
		tmp -= *find_it++;
		if (min > tmp)
			min = tmp;
	}
	v.PB(sum - min);
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
	while (t--)	search();
	printv();
	return (0);
}