,,#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    int tmp = n;
    if (n > m){
        n = m; 
        m = tmp;
    }
    vector<int> a;
    tmp = -1;
    for (int i = 1; i <= n; i++){
        if (m % i == 0 && n & i == 0)
            tmp = i;
    }
    a.push_back(tmp);
    tmp = i
    for (tmp = 1; (tmp * m) % n; tmp++) {}
    a.push_back(tmp);
    return a;
}