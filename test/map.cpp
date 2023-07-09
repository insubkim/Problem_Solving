#include <iostream>
#include <map>

using namespace std;

typedef map<int, int> mii;

mii m;

int	main()
{
	m[0] = 1;
	m[1] = 2;
	m[4] = 3;
	m[4] = m[4] + 1;
	// for (auto x : m){
	// 	cout << x.first << " " << x.second <<endl;
	// }
	// cout << "size :" << m.size() << endl;
	if (m.find(4) != m.end())
		cout << "4 : Yes" << endl;
	else
		cout << "4 : No" << endl;
	if (m.find(5) != m.end())
		cout << "5 : Yes" << endl;
	else
		cout << "5 : No" << endl;

}