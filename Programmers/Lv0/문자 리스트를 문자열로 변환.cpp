#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

string solution(vector<string> arr) {
	string a;
    return accumulate(arr.begin(), arr.end(), a);
}

int main(){
	vector<string> a;
	string a1 = "a";
	string a2 = "b";
	string a3 = "c";
	a.push_back(a1);
	a.push_back(a2);
	a.push_back(a3);

	string k = solution(a);
	cout << k << endl;
	return 0;
}