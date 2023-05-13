#include <vector>
#include <iostream>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define	PB push_back
#define PP pop_back

using namespace std;

typedef	vector<int> vi;

vi	v;

int	main(){
	int	t;
	int	tmp;
	cin >> t;
	int	j = 0;
	int	sum = 0;
	REP(i, 1, t){
		cin >> tmp;
		if (tmp){
			v.PB(tmp);
			sum += v[j];
			j++;
		}else{
			j--;
			sum -= v[j];
			v.PP();
		}
	}
	cout << sum << endl;
	return (0);
}