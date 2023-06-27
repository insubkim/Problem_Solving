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
        for (int i = 1; get<0>(loc) - i >= 0; i++){
            if (visited[get<0>(loc) - i][get<1>(loc)] == 'D' && i > 2){
                bfs.push(make_tuple(get<0>(loc) - i, get<1>(loc), get<2>(loc) + 1));
                break ;
            }else if (visited[get<0>(loc) - i][get<1>(loc)] == 'D'){
                break ;
            }
            if (visited[get<0>(loc) - i][get<1>(loc)] != 'D' && get<0>(loc) - i == 0){
                bfs.push(make_tuple(get<0>(loc) - i, get<1>(loc), get<2>(loc) + 1));
                break ;
            }
        }
        for (int i = 1; get<0>(loc) + i < hei; i++){
            if (visited[get<0>(loc) + i][get<1>(loc)] == 'D' && i > 2){
                bfs.push(make_tuple(get<0>(loc) + i, get<1>(loc), get<2>(loc) + 1));
                break ;
            }else if (visited[get<0>(loc) + i][get<1>(loc)] == 'D'){
                break ;
            }
            if (visited[get<0>(loc) + i][get<1>(loc)] != 'D' && get<0>(loc) + i == hei - 1){
                bfs.push(make_tuple(get<0>(loc) + i, get<1>(loc), get<2>(loc) + 1));
                break ;
            }
        }
        for (int i = 1; get<1>(loc) - i >= 0; i++){
            if (visited[get<0>(loc)][get<1>(loc) - i] == 'D' && i > 2){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) - i, get<2>(loc) + 1));
                break ;
            }else if (visited[get<0>(loc)][get<1>(loc) - i] == 'D'){
                break ;
            }
            if (visited[get<0>(loc)][get<1>(loc) - i] != 'D' && get<1>(loc) - i == 0){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) - i, get<2>(loc) + 1));
                break ;
            }
        }
        for (int i = 1; get<1>(loc) + i < wid; i++){
            if (visited[get<0>(loc)][get<1>(loc) + i] == 'D' && i > 2){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) + i, get<2>(loc) + 1));
                break ;
            }else if (visited[get<0>(loc)][get<1>(loc) + i] == 'D'){
                break ;
            }
            if (visited[get<0>(loc)][get<1>(loc) + i] != 'D' && get<1>(loc) + i == wid - 1){
                bfs.push(make_tuple(get<0>(loc), get<1>(loc) + i, get<2>(loc) + 1));
                break ;
            }
        }
        visited[get<0>(loc)][get<1>(loc)] == 'R';        
    }
    return -1;
}

#include <iostream>

int main(){

}