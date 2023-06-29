#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int solution(vector<string> b) {
    int a = -1;
	vector<string> visited = b;
    pair<int, int> loc;
    for (int i = 0; i < (int)b.size(); i++){
        for (int j = 0; j < (int)b[i].size(); j++){
            if (b[i][j] == 'R'){
                loc.first = i;
                loc.second = j;
                a = 0;
				break ;
            }
        }
        if (a == 0)
            break ;
    }
    queue <pair<int, int>> bfs;
    queue <int> num;
	int wid = b[0].size();
    int hei = b.size();
	int	x,y;
    bfs.push(loc);
	num.push(0);
	while (bfs.size()){
		loc = bfs.front();
		a = num.front();
		bfs.pop();
		num.pop();
		y = loc.first;
		x = loc.second;
		if (visited[y][x] == 'G')
			return a;
		visited[y][x] = 'R';
		a++;
		//down
		for (int i = y + 1; i < hei; i++){
			if (((visited[i][x] == '.' || visited[i][x] == 'G') && i == hei - 1)){
				bfs.push(make_pair(i, x));
				num.push(a);
				break ;
			}else if(visited[i][x] == 'D'){
				if ((visited[i - 1][x] == '.' || visited[i - 1][x] == 'G')){
					bfs.push(make_pair(i - 1, x));
					num.push(a);
				}
				break ;
			}
		}
		//up
		for (int i = y - 1; i >= 0; i--){
			if (((visited[i][x] == '.' || visited[i][x] == 'G') && i == 0)){
				bfs.push(make_pair(i, x));
				num.push(a);
				break ;
			}else if(visited[i][x] == 'D'){
				if ((visited[i + 1][x] == '.' || visited[i + 1][x] == 'G')){
					num.push(a);
					bfs.push(make_pair(i + 1, x));
				}
				break ;
			}
		}
		//left
		for (int i = x - 1; i >= 0; i--){
			if (((visited[y][i] == '.' || visited[y][i] == 'G') && i == 0)){
				num.push(a);	
				bfs.push(make_pair(y, i));
				break ;
			}else if(visited[y][i] == 'D'){
				if ((visited[y][i + 1] == '.' || visited[y][i + 1] == 'G')){
					num.push(a);
					bfs.push(make_pair(y, i + 1));
				}break ;
			}
		}
		//right
		for (int i = x + 1; i <= wid; i++){
			if (((visited[y][i] == '.' || visited[y][i] == 'G') && i == wid - 1)){
				bfs.push(make_pair(y, i));
				num.push(a);
				break ;
			}else if(visited[y][i] == 'D'){
				if ((visited[y][i - 1] == '.' || visited[y][i - 1] == 'G')){
					bfs.push(make_pair(y, i - 1));
					num.push(a);
				}
				break ;
			}
		}
	}
    return -1;
}

#include <iostream>
int main(){
	vector<string> a = {"..." , "...", "R.G"};
	int k = solution(a); 
	cout << k << endl;
}