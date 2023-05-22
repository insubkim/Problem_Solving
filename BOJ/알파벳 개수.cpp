#include <iostream>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int	main(){
	int c[26] = {0,};
	char t[101] = {0,};
	cin >> t;
	char *p = t;
	while (*p){
		c[*p++ - 97]++;
	}
	REP(i, 0, 25){
		cout << c[i];
		if (i == 25)
			cout << endl;
		else
			cout << " ";
	}
	return (0);
}