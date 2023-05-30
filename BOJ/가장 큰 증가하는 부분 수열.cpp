//#include <bits/stdc++.h>
#include <iostream>
#include <vector>


#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

vector<int> v1;
vector<int> dp;
int main(){
	int n;
	cin >> n;
	int tmp;
	REP(i, 1, n){
		cin >> tmp;
		v1.PB(tmp);
		dp.PB(tmp);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			if (v1[j] < v1[i] && dp[j] + v1[i] > dp[i]){
				dp[i] = dp[j] + v1[i];
			} 
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++){
		if (dp[i] > dp[mx])
			mx = i;
	}
	// int len = 1;
	// for (int i = mx - 1; i >= 0; i--){
	// 	if (v1[i] < v1[mx]){
	// 		len++;
	// 		mx = i;
	// 	}
	// }
	cout << dp[mx] << endl;
}