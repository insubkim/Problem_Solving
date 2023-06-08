#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool    c(vector<int>a, vector<int>b){
    return (a[1] < b[1]);
}


int solution(vector<vector<int>> t) {
    int a = 0;
    sort(t.begin(), t.end(), c);
    int m;
    for (int i = 0; i < (int)t.size(); i++){
        m = t[i][1];
        a++;
        i++;
        while (i < (int)t.size() && t[i][0] <= m){
            i++;
        }
        i--;
    }
    return a;
}