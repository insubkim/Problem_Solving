#include <string>
#include <vector>
#include <queue>
#include <utility>


using namespace std;

int px = 0;
int py = 0;

int lx = 0;
int ly = 0;

int ex = 0;
int ey = 0;

int w;
int h;

void    get(vector<string> maps){
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            if (maps[y][x] == 'S')
            {
                px = x;
                py = y;
            }
            else if (maps[y][x] == 'L')
            {
                lx = x;
                ly = y;
            }
            else if (maps[y][x] == 'E')
            {
                ex = x;
                ey = y;
            }
        }   
    }
}


int bfs(vector<string> maps, int px, int py, int ex, int ey){
    queue<pair<int, int>> q;
    queue<int> qt;
    int    t;
    q.push(make_pair(px, py));
    qt.push(0);
    pair<int,int>    p;
    while (q.size() > 0){
        //dequeue
        px = q.front().first;
        py = q.front().second;
        q.pop();
        t = qt.front();
        qt.pop();
        //목표지점인지 확인
        if (px == ex && py == ey)
            return t;
        t++;
        maps[py][px] = 'X';
        //주변에 visit 안햇으면 enqueue
        //위
        if (py - 1 >= 0 && maps[py - 1][px] != 'X'){
            q.push(make_pair(px, py - 1));
            qt.push(t);
        }
        //왼쪽
        if (px - 1 >= 0 && maps[py][px - 1] != 'X'){
            q.push(make_pair(px - 1, py));
            qt.push(t);
        }
        //아래
        if (py + 1 < h && maps[py + 1][px] != 'X'){
            q.push(make_pair(px, py + 1));
            qt.push(t);
        }
        //오른쪽
        if (px + 1 < w && maps[py][px + 1] != 'X'){
            q.push(make_pair(px + 1, py));
            qt.push(t);
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int a = 0;
    int tmp;
    
    w = (int)maps[0].size();
    h = (int)maps.size();

    get(maps);
    tmp = bfs(maps, px, py, lx, ly);
    if (tmp == -1)
        return -1;
    a += tmp;
    tmp = bfs(maps, lx, ly, ex, ey);
    if (tmp == -1)
        return -1;
    return a + tmp;
}


#include <iostream>
int main(){
    vector<string> m{"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
    
    int i = solution(m);
    cout << i << endl;
}