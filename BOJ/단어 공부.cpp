#include <iostream>
#include <string>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int	main(){
	string a;
	int	c[26] = {0,};
	cin >> a;
	int	max = 0;
	REP(i, 0, a.size() - 1){
		if ('A' <= a[i] && a[i] <= 'Z'){
			c[a[i] - 65]++;
			if (c[a[i] - 65] > max){
				max = c[a[i] - 65];
			}
		}else{
			c[a[i] - 97]++;
			if (c[a[i] - 97] > max){
				max = c[a[i] - 97];
			}
		}
	}
	char	k = 0;
	REP(i, 0, 25){
		if (c[i] == max){
			if (!k){
				k = i + 65;
			}else{
				cout << '?' << endl;
				return 0;
			}
		}
	}
	cout << k << endl;
	return (0);
}