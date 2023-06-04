#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> p, vector<string> c) {
    map<string, int> m;
    for (int i = 0; i < p.size(); i++){
        map[p[i]] = 0;
    }
    int r;
    string s;
    for (auto x : c){
        r = map[x];
        if (r == 0){
            continue ;
        }
        //map update
        //p update
    }

    return p;
}