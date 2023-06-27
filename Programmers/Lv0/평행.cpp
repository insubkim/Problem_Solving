#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
	int c1;
	int c2;

	c1 = (dots[0][0] - dots[1][0]) * (dots[2][1] - dots[3][1]);
	c2 = (dots[2][0] - dots[3][0]) * (dots[0][1] - dots[1][1]);
	if (c1 == c2)
		return 1;
	c1 = (dots[0][0] - dots[2][0]) * (dots[1][1] - dots[3][1]);
	c2 = (dots[1][0] - dots[3][0]) * (dots[0][1] - dots[2][1]);
	if (c1 == c2)
		return 1;
	c1 = (dots[0][0] - dots[3][0]) * (dots[2][1] - dots[1][1]);
	c2 = (dots[2][0] - dots[1][0]) * (dots[0][1] - dots[3][1]);
	if (c1 == c2)
		return 1;
	return 0;
}


#include <iostream>
int main(){
	vector<int> a1 = {1,1};
	vector<int> a4 = {4,4};
	vector<int> a2 = {2,2};
	vector<int> a3 = {3,3};
	
	vector<vector<int>> k = {a3,a1,a4,a2};
	int kk = solution(k);
	cout << kk;
}