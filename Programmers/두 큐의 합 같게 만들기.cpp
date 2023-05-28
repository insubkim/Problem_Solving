#include <string>
#include <vector>

using namespace std;

unsigned long long q_sum(vector<int> q){
    unsigned long long sum = 0;
    for (auto x : q){
        sum += x;
    }
    return (sum);
}

int solution(vector<int> q1, vector<int> q2) {
    int answer = -1;
    unsigned long long sum = q_sum(q1) + q_sum(q2);
    if (sum % 2)
        return -1;
    sum = sum / 2;
    
    return answer;
}
