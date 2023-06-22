#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;
typedef queue<int> qi;


int n, k;

void	solve(void){
	string tmp;
	//vi arr(n + 1);
	//REP(i, 1, n){
	//	cin >> tmp;
	//	arr[i] = tmp.size();
	//}
	long long a = 0;
	int	len;
	qi q[21];
	REP(i, 1, n){
		cin >> tmp;
		len = tmp.size();
		while (q[len].size() > 0 && i - q[len].front() > k){
			q[len].pop();
		}
		a += q[len].size();
		q[len].push(i);
	}
	cout << a << endl;
}

int main(){
	cin >> n >> k;
	solve();
	return 0;
}   