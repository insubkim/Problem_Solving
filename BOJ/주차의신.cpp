#include <iostream>
#include <vector>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

vi v;
int	n;

void	search(void){
	cin >> n;
	int	min = 100;
	int	max = -1;
	int tmp;
	while (n--){
		cin >> tmp;
		if (tmp < min)
			min = tmp;
		if (tmp > max)
			max = tmp; 
	}
	v.push_back((max - min) << 1);
}

int	main(){
	int	t;
	cin >> t;
	while (t--) search();
	for (auto x : v){
		cout << x << endl;
	}

}