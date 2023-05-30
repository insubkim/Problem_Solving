//#include <bits/stdc++.h>
#include <iostream>
#include <vector>


#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<int> vi;

vi v;

int main(){
	int n,tmp;
	cin >> n;
	REP(i, 1, n){
		cin >> tmp;
		v.PB(tmp);
	}
	int m = 1;
	int is_asc = 0;
	int f = 0;
	for (int i = 0; i < n; i++){
		is_asc = -1;
		f = 0;
		int j;
		for (j = i + 1; j < n; j++){
			if (is_asc == -1){
				if (v[j - 1] < v[j]){
					is_asc = 1;
				}else{
					is_asc = 0;
				}
				f++;
			}else{
				if (is_asc && v[j - 1] > v[j]){
					is_asc = 0;
					f++;
				}else if (!is_asc && v[j - 1] < v[j]){
					is_asc = 1;
					f++;
				}
				if (f == 3)
					break ;
			}
		}
		j--;
		if (m < j - i + 1){
			m = j - i + 1;
		}
	}
	cout << m << endl;
	return (0);
}