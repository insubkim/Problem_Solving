//#include <bits/stdc++.h>
#include <iostream>
#include <vector>


#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

int	main(){
	int n,tmp;
	cin >> n;
	vector<int> v;
	vector<int> dp(n, 1);
	REP(i, 1, n){
		cin >> tmp;
		v.PB(tmp);
	}
	for (int i = n - 1; i >= 0; i--){
		for (int j = n - 1; i < j; j--){
			if (v[i] > v[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	int mx = 1;
	REP(i, 0, n - 1){
		if (dp[i] > mx)
			mx = dp[i];
	}
	cout << mx << endl;
	return 0;
}