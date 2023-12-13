#include <string>
#include <vector>

using namespace std;

bool  hasOil(const vector<vector<int> >& land, int y, int x) {
  return land[y][x] == 1;
}

bool  canVisit(const vector<vector<int> >& land, int y, int x) {
  return \
        (0 <= y && y < land.size()) &&
        (0 <= x && x < land[0].size()) &&
        hasOil(land, y, x);
}

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(vector<vector<int> >& land, int y, int x) {
  int sum = 0;

  if (!hasOil(land, y, x)) //  if already visited (y, x) or no oil
    return 0;

  land[y][x] = 'X'; //mark as visited
  sum++;
  for (int i = 0; i < 4; i++) {
    int yy = y + dy[i];
    int xx = x + dx[i];
    if (canVisit(land, yy, xx)) {
      sum += dfs(land, yy, xx);
    }
  }
  return sum;
}

/*
 * parameter
 * land :
 *        0 < width <= 500
 *        0 < length <= 500
 *        land[y][x] = 1(contains oil) or 0(no oil)
 * return
 * max oil sum on one visiting col vectors
 */
int solution(vector<vector<int> > land) {
    int oil_max = 0;
    int length  = land.size();
    int width   = land[0].size();

    for (int i = 0; i < length; i++) {
      for (int j = 0; j < length; j++) {
        dfs(land, i, j);
      }
    }

    return oil_max;
}