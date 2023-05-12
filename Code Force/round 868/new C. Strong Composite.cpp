#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <map>


#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef multiset<int> mi;
typedef vector<int> vi;

mi	m;
vi	v;
vi	a;
vi	b;

void	solve(void){
	int	n,tmp,prime_num = 0;
	cin >> n;
	while (n--){
		cin >> tmp;
		a.PB(tmp);
	}
	for(int	i = 0; i < a.size(); i++){
		int	su = a[i];
		//소인수 분해 해서 multiset에 넣기
		//해당 값이 없으면 소수++
		for(int i = 2; i <= su; i++){
			if (su % i == 0){
				if (!m.count(i)){
					prime_num++;
					b.PB(i);
				}
				m.insert(i);
				su = su / i;
				i--;
			}
		}
	}
	//약수 갯수 구하기
	int	size = 1;
	int	s = 0;
	for (int i = 0; i < b.size(); i++){
		size *= m.count(b[i]) + 1;
		s += m.count(b[i]);
	}
	if (size - prime_num - 1 >= prime_num){
		v.PB(s / 2);
	}else{
		v.PB(0);
	}
	a.clear();
	m.clear();
}

int	main(){
	int	t;
	cin >> t;
	while (t--)	solve();
	vector<int>::iterator it;
	for(it = v.begin(); it != v.end(); it++){
		cout << *it << endl;
	}
	return (0);
}