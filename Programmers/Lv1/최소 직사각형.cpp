#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> s) {
    int a = 0;
    int m1 = 0;
    int m2 = 0;
    int t1,t2;
    for (auto x : s){
        t1 = max(x[0]. x[1]);
        t2 = min(x[0]. x[1]);
        if (m1 < t1)
            m1 = t1;
        if (m2 < t2)
            m2 = t2;
    }
    return m1 * m2;
}