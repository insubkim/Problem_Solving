 #include <bits/stdc++.h>
// #include <set>
// #include <vector>
// #include <iostream>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back
using namespace std;

typedef	vector<int> vi;

vi	v;
vi	bag;

void	solve(void){
	int	n,tmp,pp,contrast = 0;
	cin >> n;
	REP(k, 1, n){
		cin >> tmp;
		bag.PB(tmp);
		if (k == 1){
			pp = tmp;
		}else{
			contrast += tmp > pp ? tmp - pp : pp - tmp;
		}
	}
		int	cnt = 1;
	if (n == 1){
		bag.clear();
		v.PB(1);	
		return ;
	}else{
		int	flag = 0;
		REP(i, 1, n - 1){
			if (flag == 0){
				if (bag[i - 1] < bag[i]){
					flag = 1;
					cnt++;
				}else if (bag[i - 1] > bag[i]){
					flag = -1;
					cnt++;
				}
			}else{
				if (flag == 1 && bag[i - 1] > bag[i]){
					flag = -1;
					cnt++;
				}else if (flag == -1 && bag[i - 1] < bag[i]){
					flag = 1;
					cnt++;
				}
			}
		}
	}
	v.PB(cnt);
	bag.clear();
}

void	printv(void){
	vi::iterator it;
	for (it = v.begin(); it != v.end(); it++){
		cout << *it << endl;
	}
}

int	main(){
	int	t;
	cin >> t;
	while (t--)	solve();
	printv();
	return (0);
}