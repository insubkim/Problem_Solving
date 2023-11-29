#include <iostream> 

using namespace std;

int map[500][500];

int length, width;

int max_sum;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int visited[500][500];

bool  canVisit(int y, int x) {
  return (0 <= y && y < length) && (0 <= x && x < width) && !visited[y][x];
}

void dfs(int y, int x, int visited_num, int sum){
  if (visited_num == 4){
    if (sum > max_sum) max_sum = sum;
    return ;
  }
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++){
    int yy = y + dy[i];
    int xx = x + dx[i];
    if (canVisit(yy, xx)) {
      dfs(yy, xx, visited_num + 1, sum + map[yy][xx]);
      if (visited_num == 2) {
        int left_dir = (i + 1) % 4;
        int yyy = y + dy[left_dir];
        int xxx = x + dx[left_dir];
        if (canVisit(yyy, xxx) && max_sum < sum + map[yy][xx] + map[yyy][xxx]) 
          max_sum = sum + map[yy][xx] + map[yyy][xxx];
       }
    }
  }
  visited[y][x] = 0;
}

void solve(){
  for (int i = 0; i < length; i++){
    for (int j = 0; j < width; j++){
      dfs(i, j, 1, map[i][j]);
    } 
  }
}

int main(){
  cin >> length >> width;

  for (int i = 0; i < length; i++){
    for (int j = 0; j < width; j++){
      cin >> map[i][j];
    } 
  }
  solve();
  cout << max_sum;
}