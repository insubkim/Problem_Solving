#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool	cmp1(vector<int> i, vector<int> j){
	if (i[0] < j[0])
		return true;
	else if (i[0] > j[0])
		return false;
	else if (i[1] > j[1])
		return true;
	return false;
}

bool	sum(vector<int> i, vector<int> j){
	if (i[0] + i[1] > j[0] + j[1])
		return true;
	return false;
}

int solution(vector<vector<int>> s) {
	int first1 = s[0][0];
	int first2 = s[0][1];
	sort(s.begin(), s.end(), cmp1);
	//get min val in each section

	//if next sections min val 


	sort(s.begin(), s.end(), sum);
	int a = 1;
	for (auto x : s){
		if (x[0] == first1 && x[1] == first2)
			return a;
		a++;
	}
    return -1;
}

#include <iostream>
int main(){
	vector<int> a1 = {2,2};
	vector<int> a2 = {1,4};
	vector<int> a3 = {3,2};
	vector<int> a4 = {3,2};
	vector<int> a5 = {2,1};

	vector<vector<int>> k = {a1,a2,a3,a4,a5};
	int  a = solution(k);
	cout << a << endl;
	return 0;
}