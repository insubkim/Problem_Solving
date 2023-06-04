 #include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    if (ineq[0] == '>'){
        if (eq[0] == '='){
            return n >= m;   
        }else{
            return n > m;
        }
    }else{
        if (eq[0] == '='){
            return n <= m;
        }else{
            return n < m;
        }
    }
}