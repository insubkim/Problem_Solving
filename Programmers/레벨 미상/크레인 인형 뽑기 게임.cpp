#include <string>
#include <vector>

#define	PB push_back

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int	r = 0;
	vector<int> ba;
	for(int i = 0; i < (int)moves.size(); i++){
		int doll = 0;
		for (int k = 0; k < (int)board.size(); k++){
			if (board[k][moves[i] - 1] > 0){
				doll = board[k][moves[i] - 1];
				board[k][moves[i] - 1] = 0;
				break ;
			}
		}
		if (doll){
			ba.PB(doll);
		}else{
			continue ;
		}
		if (ba.size() > 1){
			int a = ba.back();
			ba.pop_back();
			int b = ba.back();
			ba.pop_back();
			if (a!=b){
				ba.PB(b);
				ba.PB(a);
			}else{
				r += 2;
			}
		}
	}
	return (r);
}

using namespace std;
#include <iostream>

int	main(){
	vector<int> a = {1,5,3,5,1,2,1,4};
	vector<int> a1 = {0,0,0,0,0};
	vector<int> a2 = {0,0,1,0,3};
	vector<int> a3 = {0,2,5,0,1};
	vector<int> a4 = {4,2,4,4,2};
	vector<int> a5 = {3,5,1,3,1};
	vector<vector<int>> b = {a1,a2,a3,a4,a5};
	int	i = solution(b, a);
	cout << i << endl;
	return (0);
}