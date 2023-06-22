#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool	cmp1(vector<int> i, vector<int> j){
	if (i[0] > j[0])
		return true;
	else if (i[0] < j[0])
		return false;
	else if (i[1] > j[1])
		return true;
	return false;
}

bool	cmp2(vector<int> i, vector<int> j){
	if (i[1] > j[1])
		return true;
	else if (i[1] < j[1])
		return false;
	else if (i[0] > j[0])
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
	vector<vector<int>> c1 = s;
	vector<vector<int>> c2 = s;
	sort(c1.begin(), c1.end(), cmp1);
	sort(c2.begin(), c2.end(), cmp2);

	int m0 = c1[0][0];
	int	m1 = c1[0][1];
	for (auto x : c2){
		if (x[1] < m1)
			break ;
		if (x[0] < m0)
			m0 = x[0];
	}
	
	int min_m0 = m0;
	
	m0 = c2[0][0];
	m1 = c2[0][1];
	for (auto x : c1){
		if (x[0] < m0)
			break ;
		if (x[1] < m1)
			m1 = x[1];
	}

	int min_m1 = m1;

	for (int i = 0; i < (int)s.size(); i++){
		if (s[i][0] < min_m0 && s[i][1] < min_m1){
			s.erase(s.begin() + i);
			i--;
		}
	}

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