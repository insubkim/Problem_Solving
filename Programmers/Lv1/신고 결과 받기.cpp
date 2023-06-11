#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id, vector<string> r, int k) {
    vector<int> a(id.size(), 0);
    map<string, set<string>> black;
    map<string, int>targeted_num;
    string chooser;
    string target;
    for (auto x : r){
        chooser = x.substr(0, x.find(' '));
        target = x.substr(x.find(' ') + 1, x.length());
        if (black[chooser].find(target) == black[chooser].end())
            targeted_num[target]++;
        black[chooser].insert(target);
    }
    int i = 0;
    for (auto x : id){
        set<string>::iterator it;
        for(it = black[x].begin(); it != black[x].end(); it++){
            if (targeted_num[*it] >= k){
                a[i]++;
            }
        }
        i++;
    }
    return a;
}

#include <iostream>

int main(){
    vector<string> id ={"muzi", "frodo", "apeach", "neo"};
    vector<string> r ={"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};

    vector<int> a = solution(id, r, 2);
    for (int x : a){
        cout << x << endl;
    }
    return 0;
}