#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef struct s_visited {
  int v[10][10][10][10] = {
      0,
  };
} t_visited;

typedef struct s_pos {
  int redX;
  int redY;
  int blueX;
  int blueY;
  int cnt;
} t_pos;

int N, M;
vector<string> map;

t_visited visited;

t_pos pos;

t_pos rollUp(int &redOut, int &blueOut) {
  t_pos tmp = pos;
  if (pos.redX == pos.blueX) {
    if (tmp.redY < tmp.blueY) {
      while (map[tmp.redY - 1][pos.redX] == '.') tmp.redY--;
      if (map[tmp.redY - 1][pos.redX] == 'O') redOut = 1;
      while (map[tmp.blueY - 1][pos.blueX] == '.') tmp.blueY--;
      if (map[tmp.blueY - 1][pos.blueX] == 'O') blueOut = 1;
      if (tmp.redY == tmp.blueY) tmp.blueY++;
    } else {
      while (map[tmp.blueY - 1][pos.blueX] == '.') tmp.blueY--;
      if (map[tmp.blueY - 1][pos.blueX] == 'O') blueOut = 1;
      while (map[tmp.redY - 1][pos.redX] == '.') tmp.redY--;
      if (map[tmp.redY - 1][pos.redX] == 'O') redOut = 1;
      if (tmp.redY == tmp.blueY) tmp.redY++;
    }
  } else {
    while (map[tmp.redY - 1][pos.redX] == '.') tmp.redY--;
    if (map[tmp.redY - 1][pos.redX] == 'O') redOut = 1;
    while (map[tmp.blueY - 1][pos.blueX] == '.') tmp.blueY--;
    if (map[tmp.blueY - 1][pos.blueX] == 'O') blueOut = 1;
  }
  return tmp;
}

t_pos rollDown(int &redOut, int &blueOut) {
  t_pos tmp = pos;
  if (pos.redX == pos.blueX) {
    if (tmp.redY > tmp.blueY) {
      while (map[tmp.redY + 1][pos.redX] == '.') tmp.redY++;
      if (map[tmp.redY + 1][pos.redX] == 'O') redOut = 1;
      while (map[tmp.blueY + 1][pos.blueX] == '.') tmp.blueY++;
      if (map[tmp.blueY + 1][pos.blueX] == 'O') blueOut = 1;
      if (tmp.redY == tmp.blueY) tmp.blueY--;
    } else {
      while (map[tmp.blueY + 1][pos.blueX] == '.') tmp.blueY++;
      if (map[tmp.blueY + 1][pos.blueX] == 'O') blueOut = 1;
      while (map[tmp.redY + 1][pos.redX] == '.') tmp.redY++;
      if (map[tmp.redY + 1][pos.redX] == 'O') redOut = 1;
      if (tmp.redY == tmp.blueY) tmp.redY--;
    }
  } else {
    while (map[tmp.redY + 1][pos.redX] == '.') tmp.redY++;
    if (map[tmp.redY + 1][pos.redX] == 'O') redOut = 1;
    while (map[tmp.blueY + 1][pos.blueX] == '.') tmp.blueY++;
    if (map[tmp.blueY + 1][pos.blueX] == 'O') blueOut = 1;
  }
  return tmp;
}

t_pos rollRight(int &redOut, int &blueOut) {
  t_pos tmp = pos;
  if (pos.redY == pos.blueY) {
    if (tmp.redX > tmp.blueX) {
      while (map[tmp.redY][tmp.redX + 1] == '.') tmp.redX++;
      if (map[tmp.redY][tmp.redX + 1] == 'O') redOut = 1;
      while (map[tmp.blueY][tmp.blueX + 1] == '.') tmp.blueX++;
      if (map[tmp.blueY][tmp.blueX + 1] == 'O') blueOut = 1;
      if (tmp.redX == tmp.blueX) tmp.blueX--;
    } else {
      while (map[tmp.blueY][tmp.blueX + 1] == '.') tmp.blueX++;
      if (map[tmp.blueY][tmp.blueX + 1] == 'O') blueOut = 1;
      while (map[tmp.redY][tmp.redX + 1] == '.') tmp.redX++;
      if (map[tmp.redY][tmp.redX + 1] == 'O') redOut = 1;
      if (tmp.redX == tmp.blueX) tmp.redX--;
    }
  } else {
    while (map[tmp.redY][tmp.redX + 1] == '.') tmp.redX++;
    if (map[tmp.redY][tmp.redX + 1] == 'O') redOut = 1;
    while (map[tmp.blueY][tmp.blueX + 1] == '.') tmp.blueX++;
    if (map[tmp.blueY][tmp.blueX + 1] == 'O') blueOut = 1;
  }
  return tmp;
}

t_pos rollLeft(int &redOut, int &blueOut) {
  t_pos tmp = pos;
  if (pos.redY == pos.blueY) {
    if (tmp.redX < tmp.blueX) {
      while (map[tmp.redY][tmp.redX - 1] == '.') tmp.redX--;
      if (map[tmp.redY][tmp.redX - 1] == 'O') redOut = 1;
      while (map[tmp.blueY][tmp.blueX - 1] == '.') tmp.blueX--;
      if (map[tmp.blueY][tmp.blueX - 1] == 'O') blueOut = 1;
      if (tmp.redX == tmp.blueX) tmp.blueX++;
    } else {
      while (map[tmp.blueY][tmp.blueX - 1] == '.') tmp.blueX--;
      if (map[tmp.blueY][tmp.blueX - 1] == 'O') blueOut = 1;
      while (map[tmp.redY][tmp.redX - 1] == '.') tmp.redX--;
      if (map[tmp.redY][tmp.redX - 1] == 'O') redOut = 1;
      if (tmp.redX == tmp.blueX) tmp.redX++;
    }
  } else {
    while (map[tmp.redY][tmp.redX - 1] == '.') tmp.redX--;
    if (map[tmp.redY][tmp.redX - 1] == 'O') redOut = 1;
    while (map[tmp.blueY][tmp.blueX - 1] == '.') tmp.blueX--;
    if (map[tmp.blueY][tmp.blueX - 1] == 'O') blueOut = 1;
  }
  return tmp;
}

int bfs(void) {
  queue<t_pos> q;
  q.push(pos);
  while (!q.empty()) {
    pos = q.front();
    q.pop();
    if (pos.cnt >= 10) break;
    t_pos tmp;
    int redOut = 0;
    int blueOut = 0;
    tmp = rollUp(redOut, blueOut);
    if (!blueOut &&
        (!visited.v[tmp.redY][tmp.redX][tmp.blueY][tmp.blueX] || redOut)) {
      tmp.cnt = pos.cnt + 1;
      if (redOut) return tmp.cnt;
      q.push(tmp);
    }
    visited.v[tmp.redY][tmp.redX][tmp.blueY][tmp.blueX] = 1;

    redOut = 0;
    blueOut = 0;
    tmp = rollRight(redOut, blueOut);
    if (!blueOut &&
        (!visited.v[tmp.redY][tmp.redX][tmp.blueY][tmp.blueX] || redOut)) {
      tmp.cnt = pos.cnt + 1;
      if (redOut) return tmp.cnt;
      q.push(tmp);
    }
    visited.v[tmp.redY][tmp.redX][tmp.blueY][tmp.blueX] = 1;

    redOut = 0;
    blueOut = 0;
    tmp = rollDown(redOut, blueOut);
    if (!blueOut &&
        (!visited.v[tmp.redY][tmp.redX][tmp.blueY][tmp.blueX] || redOut)) {
      tmp.cnt = pos.cnt + 1;
      if (redOut) return tmp.cnt;
      q.push(tmp);
    }
    visited.v[tmp.redY][tmp.redX][tmp.blueY][tmp.blueX] = 1;

    redOut = 0;
    blueOut = 0;
    tmp = rollLeft(redOut, blueOut);
    if (!blueOut &&
        (!visited.v[tmp.redY][tmp.redX][tmp.blueY][tmp.blueX] || redOut)) {
      tmp.cnt = pos.cnt + 1;
      if (redOut) return tmp.cnt;
      q.push(tmp);
    }
    visited.v[tmp.redY][tmp.redX][tmp.blueY][tmp.blueX] = 1;
  }
  return -1;
}

int main() {
  cin >> N >> M;
  string tmp;
  vector<int> k(M, 0);
  for (size_t i = 0; i < N; i++) {
    cin >> tmp;
    int j;
    j = tmp.find('R');
    if (j != string::npos) {
      tmp[j] = '.';
      pos.redY = i;
      pos.redX = j;
    }
    j = tmp.find('B');
    if (j != string::npos) {
      tmp[j] = '.';
      pos.blueY = i;
      pos.blueX = j;
    }
    map.push_back(tmp);
  }
  visited.v[pos.redY][pos.redX][pos.blueY][pos.blueX] = 1;
  pos.cnt = 0;
  cout << bfs();
  return 0;
}