#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool	cmp(vector<int>a, vector<int>b){
	if (a[0] > b[0]){
		return true;
	}else if (a[0] < b[0]){
		return false;
	}else if (a[1] < b[1]){
		return true;
	}
	return false;
}

int solution(vector<vector<int>> s) {
    int a = 0;
	sort(s.begin(), s.end(),cmp);
	int m = s[0][1];
	int prev = s[0][0];
	for (int i = 1; i < (int)s.size(); i++){
		if (s[i][0] == prev){
			m = s[i][1];
			continue ;
		}
		if (s[i][1] < m){
			s.erase(s.begin() + i);
			i--;
			continue ;
		}
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