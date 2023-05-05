#include <iostream>
#include <vector>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef vector<vector<char>> vvc;
typedef vector<char> vc;




int	m = 1;

int	n;
vvc v;

void	set_max(char **arr){
	int	eat = 0;
	char cur;
	REP(i, 0, n-1){
		REP(j, 0, n-1){
			if (j == 0){
				cur = arr[i][j];
				eat++;
			}
			else if (cur == arr[i][j])
				eat++;
			else{
				cur = arr[i][j];
				eat = 1;
			}
			if (m < eat)
				m = eat;
		}
	}
	REP(i, 0, n-1){
		REP(j, 0, n-1){
			if (j == 0){
				cur = arr[j][i];
				eat++;
			}
			else if (cur == arr[j][i])
				eat++;
			else{
				cur = arr[j][i];
				eat = 1;
			}
			if (m < eat)
				m = eat;
		}
	}
}

int	main(){
	//입력 받기
	cin >> n;
	char arr[n][n];

	REP(i, 0, n-1){
		REP(j, 0, n-1){
			cin >> arr[i][j];
		}
	}
	
	set_max((char **)arr);
	// REP(i, 0, n){
	// 	REP(j, 0 , n){
	// 		swap_left();
	// 		set_max();
	// 		swap_down();
	// 		set_max();
	// 	}
	// }
	cout << m << endl;
}