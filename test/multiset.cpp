#include <iostream>
#include <iterator>
#include <set>
#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

typedef multiset<int> mi;

mi s;

int main()
{
	s.insert(1);
	s.insert(1);
	s.insert(2);
	s.insert(1);
	
	multiset<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << endl;

}