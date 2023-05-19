#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

typedef multiset<int> mi;
typedef vector<int> vi;

int	main(){
	char	s[101] = {0,};
	int i = 1;
	cin >> s;
	char*p = s;
	while (*p){
		if (*p++ == ',')
			i++;
	}
	cout << i << endl;
	return (0);
}