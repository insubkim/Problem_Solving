#include <iostream>
#include <queue>
#include <string.h>

#define MAP_MAX_SIZE  20

#define UP            1
#define RIGHT         2
#define DOWN          3
#define LEFT          4

using namespace std;

int map_size;
int max_sum;

void  updateMax(int map[][MAP_MAX_SIZE]){
  for (int i = 0; i < map_size; i++){
    for (int j = 0; j < map_size; j++){
       max_sum = max(max_sum, map[i][j]);
    }
  }
}

void pushUp(int map[][MAP_MAX_SIZE]){
  for (int j = 0; j < map_size; j++){
    queue<int> q;
    //get
    for (int i = 0; i < map_size; i++){
      if (map[i][j] != 0){
        q.push(map[i][j]);
        map[i][j] = 0;
      }
    }
    //merge 
    //place
    int prev = 0;
    int i = 0;
    while (!q.empty()){
      if (prev == q.front()) {
        prev = map[i - 1][j] = q.front() * 2;
        prev = 0;
      } 
      else {
        prev = map[i][j] = q.front();
        i++;
      }
      q.pop();
    }
  }
}

void pushRight(int map[][MAP_MAX_SIZE]){
for (int i = 0; i < map_size; i++){
    queue<int> q;
    //get
    for (int j = map_size - 1; j >= 0; j--){
      if (map[i][j] != 0){
        q.push(map[i][j]);
        map[i][j] = 0;
      }
    }
    //merge 
    //place
    int prev = 0;
    int j = map_size - 1;
    while (!q.empty()){
      if (prev == q.front()) {
        prev = map[i][j + 1] = q.front() * 2;
        prev = 0;
      } 
      else {
        prev = map[i][j] = q.front();
        j--;
      }
      q.pop();
    }
  }
}

void pushDown(int map[][MAP_MAX_SIZE]){
  for (int j = 0; j < map_size; j++){
    queue<int> q;
    //get
    for (int i = map_size - 1; i >= 0; i--){
      if (map[i][j] != 0){
        q.push(map[i][j]);
        map[i][j] = 0;
      }
    }
    //merge 
    //place
    int prev = 0;
    int i = map_size - 1;
    while (!q.empty()){
      if (prev == q.front()) {
        prev = map[i + 1][j] = q.front() * 2;
        prev = 0;
      } 
      else {
        prev = map[i][j] = q.front();
        i--;
      }
      q.pop();
    }
  }
}

void pushLeft(int map[][MAP_MAX_SIZE]){
for (int i = 0; i < map_size; i++){
    queue<int> q;
    //get
    for (int j = 0; j < map_size; j++){
      if (map[i][j] != 0){
        q.push(map[i][j]);
        map[i][j] = 0;
      }
    }
    //merge 
    //place
    int prev = 0;
    int j = 0;
    while (!q.empty()){
      if (prev == q.front()) {
        prev = map[i][j - 1] = q.front() * 2;
        prev = 0;
      } 
      else {
        prev = map[i][j] = q.front();
        j++;
      }
      q.pop();
    }
  }
}

void  solve(int map[][MAP_MAX_SIZE], int push_num){
  if (push_num == 6) {
    updateMax(map);
    return ;
  }
  int map_copy[MAP_MAX_SIZE][MAP_MAX_SIZE];

  memcpy((void*)map_copy, (void*)map, sizeof(int) * MAP_MAX_SIZE * MAP_MAX_SIZE);
  pushUp(map_copy);
  solve(map_copy, push_num + 1);

  memcpy((void*)map_copy, (void*)map, sizeof(int) * MAP_MAX_SIZE * MAP_MAX_SIZE);
  pushRight(map_copy);
  solve(map_copy, push_num + 1);

  memcpy((void*)map_copy, (void*)map, sizeof(int) * MAP_MAX_SIZE * MAP_MAX_SIZE);
  pushDown(map_copy);
  solve(map_copy, push_num + 1);

  memcpy((void*)map_copy, (void*)map, sizeof(int) * MAP_MAX_SIZE * MAP_MAX_SIZE);
  pushLeft(map_copy);
  solve(map_copy, push_num + 1);
}

int main() {
  int map[MAP_MAX_SIZE][MAP_MAX_SIZE];

  cin >> map_size;
  for (int i = 0; i < map_size; i++){
    for (int j = 0; j < map_size; j++){
       cin >> map[i][j];
    }
  }
  solve(map, 1);
  cout << max_sum << endl;
}