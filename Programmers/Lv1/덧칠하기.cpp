#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> s) {
    int a = 1;
    int end = s[0] + m;
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] >= end){
            a++;
            end = s[i] + m;
        }
    }
    return a;
}