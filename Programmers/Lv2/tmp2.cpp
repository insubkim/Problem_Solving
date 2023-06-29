#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int solution(vector<string> b) {
    int a = -1;
    vector<string> visited = b;
    tuple<int, int, int> loc;
    for (int i = 0; i < (int)b.size(); i++){
        for (int j = 0; j < (int)b[i].size(); j++){
            if (b[i][j] == 'R'){
                get<0>(loc) = i;
                get<1>(loc) = j;
                get<2>(loc) = 0;
                a = 0;
                break ;
            }
        }
        if (a == 0)
            break ;
    }
    queue <tuple<int, int, int>> bfs;
    int wid = b[0].size();
    int hei = b.size();
    bfs.push(loc);
    while (bfs.size()){
        loc = bfs.front();
        if (visited[get<0>(loc)][get<1>(loc)] == 'G'){
            return get<2>(loc);
        }
        bfs.pop();
        visited[get<0>(loc)][get<1>(loc)] = 'R';        
        // 위 아래 오른 왼 방문하고 방문 않했으면 큐에 넣기
        for (int i = 1; get<0>(loc) - i >= 0; i++){
            //'d' 이고 이전이 '.' 혹은  끝이 '.' 일때는 방문 가능.
            if (get<0>(loc) - i == 0 && visited[get<0>(loc) - i][get<1>(loc)] == '.'){
                bfs.push(make_tuple(get<0>(loc) - i, get<1>(loc), get<2>(loc) + 1));
                break ;
            }
            else if (visited[get<0>(loc) - i][get<1>(loc)] == 'D' && visited[get<0>(loc) - i + 1][get<1>(loc)] == '.'){
                bfs.push(make_tuple(get<0>(loc) - i + 1, get<1>(loc), get<2>(loc) + 1));
                break ;
            }
			if (get<0>(loc) - i == 0 && visited[get<0>(loc) - i][get<1>(loc)] == 'G'){
                bfs.push(make_tuple(get<0>(loc) - i, get<1>(loc), get<2>(loc) + 1));
                return (get<2>(loc) + 1);
            }
            else if (visited[get<0>(loc) - i][get<1>(loc)] == 'D' && visited[get<0>(loc) - i + 1][get<1>(loc)] == 'G'){
                bfs.push(make_tuple(get<0>(loc) - i + 1, get<1>(loc), get<2>(loc) + 1));
                return (get<2>(loc) + 1);
			}
			if (visited[get<0>(loc) - i][get<1>(loc)] == 'D')
				break ;
        }
        for (int i = 1; get<0>(loc) + i < hei; i++){
            if (get<0>(loc) + i == hei - 1 && visited[get<0>(loc) + i][get<1>(loc)] == '.'){
                bfs.push(make_tuple(get<0>(loc) + i, get<1>(loc), get<2>(loc) + 1));
                break ;
            }
            else if (visited[get<0>(loc) + i][get<1>(loc)] == 'D' && visited[get<0>(loc) + i - 1][get<1>(loc)] == '.'){
                bfs.push(make_tuple(get<0>(loc) + i - 1, get<1>(loc), get<2>(loc) + 1));
                break ;
            }
			if (get<0>(loc) + i == hei - 1 && visited[get<0>(loc) + i][get<1>(loc)] == 'G'){
                bfs.push(make_tuple(get<0>(loc) + i, get<1>(loc), get<2>(loc) + 1));
				return (get<2>(loc) + 1);
			}
            else if (visited[get<0>(loc) + i][get<1>(loc)] == 'D' && visited[get<0>(loc) + i - 1][get<1>(loc)] == 'G'){
                bfs.push(make_tuple(get<0>(loc) + i - 1, get<1>(loc), get<2>(loc) + 1));
				return (get<2>(loc) + 1);
			}
			if (visited[get<0>(loc) + i][get<1>(loc)] == 'D')
				break ;
        }
        for (int i = 1; get<1>(loc) - i >= 0; i++){
            if (get<1>(loc) - i == 0 && visited[get<0>(loc)][get<1>(loc) - i] == '.'){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) - i, get<2>(loc) + 1));
                break ;
            }
            else if (visited[get<0>(loc)][get<1>(loc) - i] == 'D' && visited[get<0>(loc)][get<1>(loc) - i + 1] == '.'){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) - i + 1, get<2>(loc) + 1));
                break ;
            }
			if (get<1>(loc) - i == 0 && visited[get<0>(loc)][get<1>(loc) - i] == 'G'){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) - i, get<2>(loc) + 1));
				return (get<2>(loc) + 1);
			}
            else if (visited[get<0>(loc)][get<1>(loc) - i] == 'D' && visited[get<0>(loc)][get<1>(loc) - i + 1] == 'G'){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) - i + 1, get<2>(loc) + 1));
				return (get<2>(loc) + 1);
			}
			if (visited[get<0>(loc)][get<1>(loc) - i] == 'D')
				break ;
        }
        for (int i = 1; get<1>(loc) + i < wid; i++){
            if (get<1>(loc) + i == wid - 1 && visited[get<0>(loc)][get<1>(loc) + i] == '.'){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) + i, get<2>(loc) + 1));
                break ;
            }
            else if (visited[get<0>(loc)][get<1>(loc) + i] == 'D' && visited[get<0>(loc)][get<1>(loc) + i - 1] == '.'){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) + i - 1, get<2>(loc) + 1));
                break ;
            }
			if (get<1>(loc) + i == wid - 1 && visited[get<0>(loc)][get<1>(loc) + i] == 'G'){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) + i, get<2>(loc) + 1));
				return (get<2>(loc) + 1);
			}
            else if (visited[get<0>(loc)][get<1>(loc) + i] == 'D' && visited[get<0>(loc)][get<1>(loc) + i - 1] == 'G'){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) + i - 1, get<2>(loc) + 1));
				return (get<2>(loc) + 1);
	        }
			if (visited[get<0>(loc)][get<1>(loc) + i] == 'D')
				break ;
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