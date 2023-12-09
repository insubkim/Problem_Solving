#include <iostream>
#include <utility>

#define MAX_LENGTH 8
#define MAX_WIDTH 8

using namespace std;

int length, width;
int map[MAX_LENGTH][MAX_WIDTH] = {0, };
int virus_num = 0;
int virus[10][10] = {0,};

pair<int, int> wall[3];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void  dfs(int y, int x){
  for (int i = 0; i < 4; i++){
    int yy = y;
    int xx = x;
    yy += dy[i];
    xx += dx[i];
    if (0 <= xx && xx < width && 0 <= yy && yy < length && map[yy][xx] == 0){
      map[yy][xx] = 4;
      dfs(yy, xx);
    }
  }
}

int solve(){
  int max_area = 0;

  //0 empty, 1 wall, 2 virus, 3 my wall, 4 spread virus area
  for (int i = 0; i < length * width - 2; i++){
    wall[0].first = i / width;
    wall[0].second = i % width;
    if (map[wall[0].first][wall[0].second] != 0) continue;
    for (int j = i + 1; j < length * width - 1; j++){
      wall[1].first = j / width;
      wall[1].second = j % width;
      if (map[wall[1].first][wall[1].second] != 0) continue;
      for (int k = j + 1; k < length * width; k++){
        wall[2].first = k / width;
        wall[2].second = k % width;
        if (map[wall[2].first][wall[2].second] != 0) continue;
        //set wall
        map[wall[0].first][wall[0].second] = 3;
        map[wall[1].first][wall[1].second] = 3;
        map[wall[2].first][wall[2].second] = 3;
        //bfs
        for (int l = 0; l < virus_num; l++)
          dfs(virus[l][0], virus[l][1]);
        //count area
        int area = 0;
        for (int l = 0; l < length; l++){
          for (int m = 0; m < width; m++){
            if (map[l][m] == 0)
             area++;
          } 
        }
        if (max_area < area) max_area = area;
        //restore map
        for (int l = 0; l < length; l++){
          for (int m = 0; m < width; m++){
            if (map[l][m] == 3 || map[l][m] == 4)
             map[l][m] = 0;
          } 
        }
      }
    }
  }
  return max_area;
}

int main(){
  cin >> length >> width;
  for (int i = 0; i < length; i++){
    for (int j = 0; j < width; j++){
      int val;
      cin >> val;
      map[i][j] = val; 
      if (val == 2) { //virus
        virus[virus_num][0] = i;
        virus[virus_num][1] = j;
        virus_num++;
      }
    }
  }

  int max_area = solve();
  cout << max_area << endl;
}