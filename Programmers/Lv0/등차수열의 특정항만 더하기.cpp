#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> in) {
    int r = 0;
    int cnt = 0;
    for (int i = 0; i < (int)in.size(); i++){
        if (in[i] == 1){
            r += a;
            cnt += i;
        }
    }
    return r + cnt * d;
}