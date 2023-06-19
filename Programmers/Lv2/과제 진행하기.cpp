#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

bool    cmp(vector<string> i, vector<string> j){
    string s_i = i[1];
    string s_j = j[1];

    for (int k = 0; k <= 5; k++){
        if (k == 2)
            continue ;
        if (s_i[k] < s_j[k]){
            return true;
        }else if (s_i[k] > s_j[k]){
            return false;
        }
    }
    return false;
}

void print(vector<vector<string>> p) {
    for (auto x : p){
        cout << x[0] << x[1] << x[2] << endl;
    }
}

int to_min(string t){
    return ((t[0] - '0') * 10 + t[1] - '0') * 60 + (t[3] - '0') * 10 + t[4] - '0';
}

vector<string> solution(vector<vector<string>> p){
    vector<string> a;
    vector<pair<string, int>> stack;

    sort(p.begin(), p.end(), cmp);
    stack.push_back(make_pair(p[0][0], stoi(p[0][2])));
    int prev_time = to_min(p[0][1]);
    p.erase(p.begin());
    vector<string> cur;
    while (p.size() > 0){
        cur = p[0];
        p.erase(p.begin());
        while (stack.size() > 0){
            int elapse_time = to_min(cur[1]) - prev_time;
            if (elapse_time >= stack.back().second){
                a.push_back(stack.back().first);
                prev_time += stack.back().second;
                stack.pop_back();
            }else{
                stack.back().second = stack.back().second - elapse_time;
                break ;
            }
        }
        stack.push_back(make_pair(cur[0], stoi(cur[2])));
        prev_time = to_min(cur[1]); 
    }
    while (stack.size() > 0){
        a.push_back(stack.back().first);
        stack.pop_back();
    }
    return a;
}

int main(){
    vector<vector<string>> p {{"music", "12:20", "40"}, {"computer", "12:30", "100"}, {"science", "12:40", "50"}, {"history", "14:00", "30"}};
    
    vector <string> k = solution(p);
    for (auto x : k){
        cout << x << endl;
    }
}