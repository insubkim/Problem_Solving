#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> v, vector<vector<int>> c) {
    vector<int> a;
    vector<int> t;
    for (auto x : c){
        t = v;
        sort(t.begin() + x[0] - 1, t.begin() + x[1] - 1);
        a.push_back(t[t.begin() + x[0] - 1 + x[2] - 1]);
    }
    return a;
}