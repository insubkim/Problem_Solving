#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> s) {
    int a = 0;
    sort(s.begin(), s.end());
    int c = 0;
    for (int i = s.size() - 1; i >= 0; i--){
        c++;
        if (c % m == 0){
            a += m * s[i];
        }
    }
    return a;
}