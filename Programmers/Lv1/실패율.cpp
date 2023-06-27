#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool	cmp(tuple<int, int, int>a, tuple<int, int, int>b){
	long long aa = get<1>(a) * get<2>(b);
	long long bb = get<1>(b) * get<2>(a);
	if (aa > bb)
		return true;
	else if (aa < bb)
		return false;
	if (get<0>(a) < get<0>(b))
		return true;
	return false;
}

bool	rev(int a, int b){
	if (a > b)
		return true;
	return false;
}

vector<int> solution(int N, vector<int> s) {
    vector<int> a;
	sort(s.begin(), s.end(), rev);
	//vecor<pair<int, double>> rate; stage failure store
	vector<tuple<int, int, int>> rate;
	int fail_num = 0;
	int all_num = 0;
	int cur_stage = N+1;
	int i = 0;

	while (s[0] < cur_stage){
		rate.push_back(make_tuple(cur_stage--, 0 , 1));
	}

	while (cur_stage > 0){
		if (i < (int)s.size() && s[i] == cur_stage){
			fail_num++;
			all_num++;
			i++;
		}else{
			if (all_num == 0)
				rate.push_back(make_tuple(cur_stage, 0 , 1));
			else
				rate.push_back(make_tuple(cur_stage, fail_num ,all_num));
			cur_stage--;
			fail_num = 0;
		}
	}

	//sort in high failure order 
	//if same low stage comes first.
	sort(rate.begin(), rate.end(), cmp);
	for (auto x : rate){
		if (get<0>(x) ==  N + 1)
			continue ;
		a.push_back(get<0>(x));
	}
    return a;
}

#include <iostream>
int main(){
	vector<int> k = {1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,3,4};
	//12  // 3 // 1
	//16    5      2 
	vector<int> a = solution(3, k);
	for(auto x : a){
		std::cout << x << endl;
	}
}