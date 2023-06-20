#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<int> s) {
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++){
        a.push_back(make_pair(i + 1, 0));
    }
    int sub = 0;
    int people = (int)s.size();
    sort(s.begin(), s.end());
    int j = 0;
    int num;
    for (int i = 1; i <= n; i++){
        num = 0;
        for (; j < (int)s.size(); j++){
            
        }
    }
    return s;
}