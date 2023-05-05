#include <iostream>
#include <vector>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

/*

첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

*/

int	n;
int	m = 1;

void	set_max(char *b){
	//가로
	int	eat;
	REP(i, 0, n-1){
		eat = 1;
		REP(j, 1, n-1){
			if (*(b + i * n + j) == *(b + i * n + j - 1))
				eat++;
			else
				eat = 1;
			if (m < eat)
				m = eat;
		}
	}
	//세로
	REP(i, 0, n-1){
		eat = 1;
		REP(j, 1, n-1){
			if (*(b + j * n + i) == *(b + (j -1) * n + i))
				eat++;
			else
				eat = 1;
			if (m < eat)
				m = eat;
		}
	}
}

int	main(){
	cin >> n;
	//배열 생성.
	//입력 저장
	char b[n][n];
	REP(i, 0, n-1){
		REP(j, 0, n-1){
			cin >> b[i][j];
		}
	}

	//max 저장.
	set_max((char*)b);
	//0~n-1
	//0~n-1 에 대해서 로테이트
	char tmp;
	REP(i, 0, n-1){
		REP(j, 0, n-1){
			//왼쪽이랑 스왑
			if (j != n-1){
				tmp = b[i][j];
				b[i][j] = b[i][j+1];
				b[i][j+1] = tmp;
				set_max((char*)b);
				//복구
				b[i][j+1] = b[i][j];
				b[i][j] = tmp;
			}
			//아래랑 스왑
			if (i != n-1){
				tmp = b[i][j];
				b[i][j] = b[i+1][j];
				b[i+1][j] = tmp;
				set_max((char*)b);
				//복구
				b[i+1][j] = b[i][j];
				b[i][j] = tmp;
				//복구
			}
		}
	}
	cout << m <<endl;
}