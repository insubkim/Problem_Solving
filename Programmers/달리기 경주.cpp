#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> p, vector<string> c) {
    map<string, int> m;
    for (int i = 0; i < (int)p.size(); i++){
        m[p[i]] = i;
    }
    int r;
    string s;
    for (auto x : c){
        r = m[x];
        if (r == 0){
            continue ;
        }
        //map update
        m[x] = r - 1;
        s = p[r - 1];
        m[s] = r;
        //p update
        p[r - 1] = p[r];
        p[r] = s; 
    }
    return p;
}

#include <iostream>

int main(){
    vector<string> p{"mumu", "soe", "poe", "kai", "mine"};
    vector<string> c{"kai", "kai", "mine", "mine"};
    vector<string> a = solution(p, c);
    for (auto x : a){
        cout << x << endl;
    }
    return 0;   
}