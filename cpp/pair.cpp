#include <iostream>
#include <utility>

using namespace std;

typedef	pair<int, int> pi;

pi p;

int	main()
{
	p.first = 1;
	p.second = 2;
	p.second = p.second + 1;
	cout << p.first << " " << p.second << endl;

}