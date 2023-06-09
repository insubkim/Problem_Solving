//#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <map>




#define REP(i,a,b) for(int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef	vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mii;
typedef multiset<int> mi;

vpi vp;
vi v;
mii m;

bool isPrime2(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
		if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	return true;
}

int	get_prime(int n)
{
	while (!isPrime2(n)){
		n++;
	}
	return (n);
}

void	factorization(int num){
	REP(i, 1, num){
		i = get_prime(i);
		if (num % i == 0){
			if (m.find(i) != m.end())
				m[i] = m[i] + 1;
			else
				m[i] = 1;	
			num = num / i;
			i--;
		}
	}
}

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
	int	prime_num;
	int	strong_composiite_num;
	int	num;
	//소수와 s.p의 갯수 카운트
	prime_num = m.size();
	num = 1;
	for(auto x : m){
		num *= (x.second + 1);
	}
	strong_composiite_num = num - pow(2, prime_num) + 2 - 1 - 1; 
	//s.p < 소수 면 k 구하고 출력

	if (prime_num <= strong_composiite_num){
		num = 0;
		for(auto x : m){
			while (x.second > 1){
				num++;
				x.second = x.second - 2;
			}
		}
	}
	else 
		v.PB(0);
}

int	main()
{
	int	t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>t;
	while (t--) search();
	for(auto x : v){
		cout << x << endl;
	} 
	return (0);
}