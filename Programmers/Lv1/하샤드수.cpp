#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int a = 0;
    int b = x;
    while (x > 0){
        a += x % 10;
        x /= 10;
    }
    if (a % b){
        return false;
    }else{
        return true;
    }
}