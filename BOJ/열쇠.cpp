#include <iostream>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <queue>

#include <string.h>

using namespace std;

// 세로, 가로
int h, w;

// . : 땅
// * : 벽
// $ : 문서
// 알파벳 소문자 : 열쇠
// 알파벳 대문자 : 문
char map[101][101];

bool visited[101][101];

int T;

bool key[26];

int doc;

vector<pair<int, int>>door_coord[26];

bool    can_visit(int y, int x) {
    if (y < 0 || y > h + 1) {
        return false;
    }
    if (x < 0 || x > w + 1) {
        return false;
    }
    if (map[y][x] == '*') {
        return false;
    }
    if (map[y][x] == '.' || map[y][x] == 0 || map[y][x] == '$' ) {
        return true;
    }    
    if ('a' <= map[y][x] && map[y][x] <= 'z') {
        return true;
    }
    char door = map[y][x];
    if (key[door - 'A']) {
        return true;
    }
    return false;
}

void    bfs(void) {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    vector<pair<int, int>>waiting[26];

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        if (map[y][x] == '$') {
            doc++;
        }
        q.pop();

        int dy[4] = {0, -1, 0, +1};
        int dx[4] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy < 0 || yy > h + 1 || xx < 0 || xx > w + 1) {
               continue;
            }
            if (map[yy][xx] == '*') {
                continue ;
            }
            if ('A' <= map[yy][xx] && map[yy][xx] <= 'Z') {
                int k = map[yy][xx] - 'A';
                if (!key[k]) {
                    waiting[k].push_back({yy, xx});
                    continue;
                }
            }

            if ('a' <= map[yy][xx] && map[yy][xx] <= 'z') {
                int k = map[yy][xx] - 'a';
                key[k] = true;
                for (auto &p : waiting[k]) {
                    int yyy = p.first;
                    int xxx = p.second;
                    if (visited[yyy][xxx]) {
                        continue ;
                    }
                    q.push({yyy, xxx});
                    visited[yyy][xxx] = true;
                }
                waiting[k].clear();
            }
            if (!can_visit(yy, xx)) {
                continue ;
            }
            if (visited[yy][xx]) {
                continue ;
            }
            q.push({yy, xx});
            visited[yy][xx] = true;
        }
    }
}

int main(void) {
    cin >> T;

    while (T--) {
        // 가장자리 가 빈칸이거나 가장 자리 문을 열수있으면 큐에 삽입
        // bfs 실행
        // 기존키가 아닌 새로운 키를 획득하면, 해당 문을 열수있는 위치의 4 방향이 visited 이라면 큐에 삽입 

        memset(map, 0, sizeof(map));
        memset(key, 0, sizeof(key));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 26; i++) {
           door_coord[i].clear();
        }
        doc = 0;

        cin >> h >> w;
        string line;
        for (int i = 1; i <= h; i++) {
            cin >> line;
            for (int j = 1; j <= w; j++) {
                map[i][j] = line[j - 1];
                if ('A' <= map[i][j] &&  map[i][j] <= 'Z') {
                    door_coord[map[i][j] - 'A'].push_back({i, j});
                }
            }   
        }
        cin >> line;
        for (auto x : line) {
            if (line[0] == '0') {
                    break ;
            }
            key[x - 'a'] = true;
        }
        
        bfs();
        cout << doc << '\n';
    }
    return 0;
}