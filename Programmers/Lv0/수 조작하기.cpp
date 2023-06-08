#include <string>
#include <vector>

using namespace std;

/*

"w" : n이 1 커집니다.
"s" : n이 1 작아집니다.
"d" : n이 10 커집니다.
"a" : n이 10 작아집니다.

*/

int solution(int n, string c) {
    for (auto x : c){
        if (x == 'w'){
            n++;;
        }else if (x == 's'){
            n--;
        }else if (x == 'd'){
            n += 10;
        }else{
            n -= 10;
        }
    }
    return n;
}