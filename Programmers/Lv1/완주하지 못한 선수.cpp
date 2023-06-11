#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> p, vector<string> c) {
    multiset<string>m;
    for (auto x : c)
        m.insert(x);
    for (auto x : p){
        if (m.find(x) == m.end())
            return x;
        m.erase(m.find(x));
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