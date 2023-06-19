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

int get_end_time(vector<string> s){
    int hour = stoi(s[2]) / 60;
    int min = stoi(s[2]) % 60;
    return ((s[1][0] - '0') * 10 + s[1][1] - '0' + hour) * 60 + (s[1][3] - '0') * 10 + s[1][4] - '0' + min;
}



vector<string> solution(vector<vector<string>> p) {
    vector<string> a;
    vector<pair<string, int>> stack;

    sort(p.begin(), p.end(), cmp);
    vector<string> cur;
    stack.push_back(make_pair(p[0][0], get_end_time(p[0])));
    p.erase(p.begin());
    int prev_t, cur_t;
    while (p.size() > 0){
        cur = p[0];
        p.erase(p.begin());
        cur_t = ((cur[1][0] - '0') * 10 + cur[1][1] - '0') * 60 + (cur[1][3] - '0')* 10 + cur[1][4] - '0';
        while (stack.size() > 0){
            prev_t = stack.back().second;
            if (prev_t <= cur_t){
                a.push_back(stack.back().first);
                stack.pop_back();
            }else{
                stack.back().second = prev_t - cur_t;
                break ;
            }
        }
        stack.push_back(make_pair(cur[0], get_end_time(cur)));
    }
    while (stack.size() > 0){
        a.push_back(stack.back().first);
        stack.pop_back();      
    }
    
    return a;
}

int main(){
    vector<vector<string>> p {{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}};
    
    vector <string> k = solution(p);
    for (auto x : k){
        cout << x << endl;
    }
}