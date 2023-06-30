#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> a;
    if (n == 0){
        a.push_back(0);
        return a;
    }
    while (n > 0){
        a.push_back(n % 10);
        n /= 10;
    }
    return a;
}