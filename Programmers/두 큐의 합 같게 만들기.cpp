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
    unsigned long long sum = q_sum(q1) + q_sum(q2);
    if (sum % 2)
        return -1;
    sum = sum / 2;
    vector<int> q = q1;
    q.insert(q.end(), q2.begin(), q2.end());
    int s = 0;
    int e = (int)q1.size() -1;
    
    int move = 0;
    
    unsigned long long q1_sum;
    /*
        문제점.
        q1 크기가 0이면 e가 -1이됨
        e가 q.size()보다 커지면 0 부터 다시 시작해여함.
        그리고 덧셈도 다시만들어야함.
    */
    while (s < (int)q.size()){
        q1_sum = 0;
        for (int i = s; i <= e; i++){
            q1_sum += q[i];
        }
        if (q1_sum > sum){
            s++;
        }else if (q1_sum < sum){
            e++;
        }else{
            return (move);
        }
        move++;
    }
    return -1;
}

#include <iostream>

int main(){
    vector<int> q1 = {3, 2, 7, 2};
    vector<int> q2 = {1, 2, 1, 2};
    int a = solution(q1,q2);
    //cout << a << endl;
    return (0);
}