#include <iostream>
#include <vector>

#define REP(i, n, k) for(int i = n; i <= k; i++)

using namespace std;

typedef	vector<int> vi;
typedef	vector<vi> vvi;

vvi vs;
vi v;
	

using namespace std;

int	n;

void	search(void){
	cin >> n;
	if (n == 1){
		v.push_back(1);
	}
	else if (n % 2){
		v.push_back(-1);	
	}
	else{
		REP(i, 1, n){
			if (i % 2)
				v.push_back(i + 1);
			else
				v.push_back(i - 1);
		}
	}
	v.push_back(-2);	
}

int	main(){
	int	t;

	cin >> t;
	while (t--) search();
	int	flag = 0;
	for (auto x : v){
		if (x == -2){
			cout << endl;
		}
		else{
			cout << x << " ";
		}
	}	
	return (0);
}