#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
	char a[101] = {0,};
	cin >> a;
	char c;
	for (int i = 0; i < (int)strlen(a); i = i + 10){
		c = a[i + 10];
		a[i + 10] = 0;
		cout << &(a[i]) << endl;
		a[i + 10] = c;
	}
	return (0);
}