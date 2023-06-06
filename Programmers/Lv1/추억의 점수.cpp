#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> n, vector<int> y, vector<vector<string>> p) {
    vector<int> a;
    int score;
    for (auto x : p){
        score = 0;
        for (auto k : x){
            for (int i = 0; i < (int)n.size(); i++){
                if (n[i] == k){
                    score += y[i];
                    break ;
                }
            }
        }
        a.push_back(score);
    }
    return a;
}
