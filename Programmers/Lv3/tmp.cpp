#include <string>
#include <vector>
#include <algirithm>

using namespace std;

bool	cmp(<vector<int> i, <vector<int> j){
	if (i[0] > j[0])
		return true;
	return false;
}

bool	cmp(<vector<int> i, <vector<int> j){
	if (i[0] + i[1] > j[0] + j[1])
		return true;
	return false;
}

int solution(vector<vector<int>> s) {
	int first1 = s[0][0];
	int first2 = s[0][1];
	sort(s.begin(), s.end(), cmp);
	int m1 = s[0][0];
	int m2 = s[0][1];
	for (int i = 1; i < (int)s.size(); i++){
		if (s[i][0] < m1 && s[i][1] < m2){
			s.erase(s.begin() + i);
			i--;
		}else if (s[i][0] < m1){
			m1 = s[i][0];
		}else if (s[i][1] < m2){
			m2 = s[i][1];
		}
	}
	sort(s.begin(), s.end(), sum);
	for (int i = 1; i <= (int)s.size(); i++){
		if (s[i][0] == first1 && s[i][1] ==  first2)
			return i;
	}
    return -1;
}