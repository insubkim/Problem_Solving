#include <vector>
#include <iostream>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define	PB push_back

using namespace std;

typedef	vector<int> vi;

int	n;
vi v;

int	main(){
	cin >> n;
	//1번은 첫 번째
	//2번은 두 번째가 무조건 이김.
	//0
	v.PB(-1);
	//1
	v.PB(1);
	//2
	v.PB(2);
	//3
	v.PB(1);
	//4? 3과 1체크
	REP(i, 4, n){
		if (v[i - 1] == 2 || v[i - 3] == 2)
			v.PB(1);
		else
			v.PB(2);
	}
	if (v[n] == 1)
		cout << "SK";
	else
		cout << "CY";
	cout <<endl;
}