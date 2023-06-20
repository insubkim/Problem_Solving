#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>i, pair<int, int>j){
    return i.first > j.first;
}

int solution(vector<int> p, vector<string> m) {
    int a = 0;
    if ((p[0] + p[1] + p[2]) * 5 < (int)m.size()){
        m.erase(m.begin() + (int)p.size() * 5, m.end());
    }
    vector<pair<int, int>> label;
    int tmp;
    for (int i = 0; i < (int)m.size(); i++){
        tmp = 0;
        for (int j = 0; j < 5 && i + j < (int)m.size(); j++){
            if (m[i + j][0] == 'd'){
                tmp += 25;
            }else if (m[i + j][0] == 'i'){
                tmp += 5;
            }else{
                tmp += 1;
            }
        }
        label.push_back(make_pair(tmp, i));
        i += 4;
    }
    sort(label.begin(), label.end(), cmp);
    for (int i = 0; i < (int)label.size(); i++){
        if (p[0]){
            for (int j = label[i].second; j < label[i].second + 5 && j < (int)m.size(); j++){
                a++;
            }// a += label[i].second + 5 < m.size() ? 5 : m.size() - label[i].second
            p[0]--;
        }else if (p[1]){
            for (int j = label[i].second; j < label[i].second + 5 && j < (int)m.size(); j++){
                if (m[j][0] == 'd'){
                    a += 5;
                }else if (m[j][0] == 'i'){
                    a += 1;
                }else{
                    a += 1;
                }
            }
            p[1]--;
        }else if (p[2]){
            for (int j = label[i].second; j < label[i].second + 5 && j < (int)m.size(); j++){
                if (m[j][0] == 'd'){
                    a += 25;
                }else if (m[j][0] == 'i'){
                    a += 5;
                }else{
                    a += 1;
                }
            }
            p[2]--;
        }
    }
    return a;
}


#include <iostream>
int main(){
    vector<int> p = {1,1,2};
    vector<string> m = {"stone", "stone", "stone", "stone", "stone", "dia", "dia", "dia", "dia", "dia","stone", "stone", "stone", "stone", "stone", "dia", "dia", "dia", "dia", "dia"};
    int k = solution(p, m);
    cout << k << endl;

    return 1;
}