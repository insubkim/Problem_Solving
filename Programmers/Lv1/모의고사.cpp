#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> a) {
    vector<int> r;
    vector<int> a1 = {1, 2, 3, 4, 5};
    vector<int> a2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> a3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int c1,c2,c3;
    c1 = c2 = c3 = 0;
    int i1,i2,i3;
    i1 = i2 = i3 = 0;
    for (auto x : a){
        if (i1 == 5)
            i1 = 0;
        if (i2 == 8)
            i2 = 0;
        if (i3 == 10)
            i3 = 0;
        if (a1[i1++] == x)
            c1++;
        if (a2[i2++] == x)
            c2++;
        if (a3[i3++] == x)
            c3++;
    }
    int m = max(c1, c2);
    m = max(m, c3);
    if (c1 == m)
        r.push_back(1);
    if (c2 == m)
        r.push_back(2);
    if (c3 == m)
        r.push_back(3);
    return r;
}