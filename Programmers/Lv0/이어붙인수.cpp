#include <string>
#include <vector>

using namespace std;

int solution(vector<int> n) {
    int o = 0;
    int e = 0;
    for (auto x : n){
        if (x % 2 == 1)
            o = o * 10 + x;
        else
            e = e * 10 + x;
    }
    return o + e;
}