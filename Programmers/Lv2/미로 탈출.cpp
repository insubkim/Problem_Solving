#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>


using namespace std;

int px = 0;
int py = 0;

int w;
int h;

int bfs(vector<string> maps, int px, int py, char c){
    queue<pair<int, int>> q;
    queue<int> qt;
    int    t;
    q.push(make_pair(px, py));
    qt.push(0);
    maps[py][px] = 'X';
    while (q.size() > 0){
        //dequeue
        px = q.front().first;
        py = q.front().second;
        q.pop();
        t = qt.front();
        qt.pop();
        t++;
        //주변에 visit 안햇으면 enqueue
        //위
        if (py - 1 >= 0 && maps[py - 1][px] != 'X'){
            //목표지점인지 확인
            if (maps[py - 1][px] == c)
                return t;
            maps[py - 1][px] = 'X';
            q.push(make_pair(px, py - 1));
            qt.push(t);
        }
        //왼쪽
        if (px - 1 >= 0 && maps[py][px - 1] != 'X'){
            //목표지점인지 확인
            if (maps[py][px - 1] == c)
                return t;
            maps[py][px - 1] = 'X';
            q.push(make_pair(px - 1, py));
            qt.push(t);
        }
        //아래
        if (py + 1 < h && maps[py + 1][px] != 'X'){
            //목표지점인지 확인
            if (maps[py + 1][px] == c)
                return t;
            maps[py + 1][px] = 'X';
            q.push(make_pair(px, py + 1));
            qt.push(t);
        }
        //오른쪽
        if (px + 1 < w && maps[py][px + 1] != 'X'){
            //목표지점인지 확인
            if (maps[py][px + 1] == c)
                return t;
            maps[py][px + 1] = 'X';
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

    size_t pos;
    for (int i = 0; i < h; i++){    
        pos = maps[i].find('S' ,0);
        if (pos != string::npos)
        {   
            px = (int)pos;
            py = i;
            break ;
        }
    }
    tmp = bfs(maps, px, py, 'L');
    if (tmp == -1)
        return -1;
    a += tmp;
    for (int i = 0; i < h; i++){    
        pos = maps[i].find('L' ,0);
        if (pos != string::npos)
        {   
            px = (int)pos;
            py = i;
            break ;
        }
    }
    tmp = bfs(maps, px, py, 'E');
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