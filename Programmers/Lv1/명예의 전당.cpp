#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> s) {
    vector<int> a;
    vector<int> r;
    
    for (int i = 0; i < (int)s.size(); i++){
        if (i < k){
            r.push_back(s[i]);
            sort(r.begin(), r.end());
        }else if (r[0] < s[i]){
            r.erase(r.begin());
            r.push_back(s[i]);
            sort(r.begin(), r.end());
        }
        a.push_back(r[0]);    
    }
    return a;
}