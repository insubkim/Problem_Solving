#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> p, vector<string> c) {
    sort(p.begin(), p.end());
    sort(c.begin(), c.end());
    for (int i = 0; 1; i++){
        if (p[i] != c[i])
            return p[i];
    }
    return "";
}

#include <iostream>
int main(){
    multiset<string>m;
    m.insert("a");
    m.insert("a");
    m.erase(m.find("a"));
    for (auto x : m){
        cout << x << endl;
    }
    return 1;
}