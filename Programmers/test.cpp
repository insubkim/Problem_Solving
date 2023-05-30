#include <string>
#include <vector>

#define PB push_back

using namespace std;


#include <iostream>

int main(){
    vector<int> q1 = {1, 2, 1, 1};
	q1.erase(q1.begin());
	for (auto x : q1){
		cout << x << endl;
	}
    return (0);
}