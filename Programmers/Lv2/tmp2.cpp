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
    int wid = b[0].size();
    int hei = b.size();
    bfs.push(loc);
	while (bfs.size()){
		//pop front
		loc = bfs.front();
		bfs.pop();
		a++;
		//visit place and put in queue
		//check visit place is destination
		//if yes return a 
	
		//up

		//down

		//left

		//right
		}
    return -1;
}

#include <iostream>
int main(){
	vector<string> a = {"..." , "...", "R.G"};
	int k = solution(a); 
	cout << k << endl;
}