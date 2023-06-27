#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    while (n--){
        answer.push_back(x);
        x += x;
    }
    return answer;
}