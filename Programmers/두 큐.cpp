#include <string>
#include <vector>

#define PB push_back

using namespace std;

unsigned long long q_sum(vector<int> q){
    unsigned long long sum = 0;
    for (auto x : q){
        sum += x;
    }
    return (sum);
}

void	enqueue(vector<int> q, int val){
	q.PB(val);
}

int	dequeue(vector<int> q){
	if (q.size() > 0){
		int val = q[0];
		q.erase(q.begin());
		return (val);
	}else{
		return (-1);
	}
}

int solution(vector<int> q1, vector<int> q2) {
    unsigned long long sum = q_sum(q1) + q_sum(q2);
    if (sum % 2)
        return -1;
    sum = sum / 2;
	int	move = 0;
	for (int i = 0; i < (int)q1.size() + (int)q2.size(); i++){
		unsigned long long sum1 = q_sum(q1);
		if (sum == sum1){
			return (move);
		}else if (sum < sum1){
			int val = dequeue(q1);
			enqueue(q2, val);
		}else{
			int val = dequeue(q2);
			enqueue(q1, val);
		}
		move++;
	}
    return -1;
}

#include <iostream>

int main(){
    vector<int> q1 = {3, 2, 7, 2};
    vector<int> q2 = {4, 6, 5, 1};
    int a = solution(q1,q2);
    cout << a << endl;
    return (0);
}