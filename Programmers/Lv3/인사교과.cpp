#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool	cmp(vector<int> i, vector<int> j){
	if (i[0] + i[1] < j[0] + j[1]){
		return true;
	}
	return false;
}

int solution(vector<vector<int>> s) {
    vector<int> p = s[0];
	//각 자리 max 찾기.
	vector<int> f_max = p;
	vector<int> s_max = p;

	for (auto x : s){
		if (f_max[0] < x[0]){
			f_max = x;
		}
		if (s_max[1] < x[1]){
			s_max = x;
		}
	}
	for (int i = 0; i < s.size(); i++){
		if ((s[i][0] < f_max[0] && s[i][1] < f_max[1]) || (s[i][0] < s_max[0] && s[i][1] < s_max[1])){
			if (s[i][0] == p[0] && s[i][1] == p[1])
				return -1;
			s.erase(s.begin() + i);
            i--;
		}
	}

	//등수
	sort(s.begin(), s.end(), cmp);
	int a = 1;
	vector<vector<int>>::reverse_iterator ri;
	for (ri = s.rbegin(); ri != s.rend(); ri++){
		if ((*ri)[0] == p[0] && (*ri)[1] == p[1])
			break ;
		a++;
	}
    return a;
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