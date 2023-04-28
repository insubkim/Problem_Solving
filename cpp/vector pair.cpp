#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pi;


vpi vp;
pi p;
pi p2;
int	main(){
	p.first = 1;
	p.second = 2;

	p2.first = 2;
	p2.second = 2;
	vp.push_back(p);
	vp.push_back(p2);
	for (auto x : vp){
		cout << x.first << " " <<x.second << endl;
	}
	cout << "size :" << vp.size() << endl;
	return (0); 
}