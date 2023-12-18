#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void  completeSearch(int hp, vector<vector<int>> dungeons, vector<bool> selected, int& max_visit) {
  for (size_t i = 0; i < dungeons.size(); i++) {
    if (selected[i]) continue;
    if (dungeons[i][0] <= hp) {
      selected[i] = true;
      if (max_visit < std::count(selected.begin(), selected.end(), true)) max_visit++;
      completeSearch(hp - dungeons[i][1], dungeons, selected, max_visit);
    }
    selected[i] = false;
  }
}


int solution(int hp, vector<vector<int>> dungeons) {
    int max_visit = 0;
    vector<bool> selected(dungeons.size(), 0);
    completeSearch(hp, dungeons, selected, max_visit);
    return max_visit;
}