#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> r) {
    sort(r.begin(), r.end());
    vector<int> s(n, 1);
    for (int i = 0; i < (int)lost.size(); i++){
        s[lost[i] - 1] = 0;
        n--;
    }
    for (int i = 0; i < (int)r.size(); i++){
        if (!s[r[i] - 1]){
            s[r[i] - 1] = 1;
            n++;
            r[i] = -1;
        }
    }
    for (int i = 0; i < (int)r.size(); i++){
        if (r[i] == -1)
            continue ;
        if (r[i] - 2 >= 0 && !s[r[i] - 2]){
            s[r[i] - 2] = 1;
            n++;
        }else if (r[i] < s.size() && !s[r[i]]){
            s[r[i]] = 1;
            n++;
        }
    }
    return n;
}


#include <iostream>
int main(){
    vector<int> l = {1,2,3,4,5};
    vector<int> r = {1,3,5};
    int a = solution(5, l, r);
    cout << a << endl;
    return 1;
}