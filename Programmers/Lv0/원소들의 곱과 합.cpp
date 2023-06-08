#include <string>
#include <vector>

using namespace std;

int solution(vector<int> n) {
    int k1 = 1;    
    int k2 = 0;    
    for (auto x : n){
        k1 *= x;
        k2 +=  x;
    }
    k2 *= k2;
    return k1 < k2 ? 1 : 0; 
}