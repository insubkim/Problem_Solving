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

void	enqueue(vector<int> &q, int val){
	q.PB(val);
}

int	dequeue(vector<int> &q){
	if (q.size() > 0){
		int val = q[0];
		q.erase(q.begin());
		return (val);
	}else{
		return (-1);
	}
}

#include <iostream>
int solution(vector<int> q1, vector<int> q2) {
    unsigned long long sum = q_sum(q1) + q_sum(q2);
    if (sum == 0)
		return (0);
	if (sum % 2)
        return -1;
    sum = sum / 2;
	int	move = 0;
	unsigned long long sum1 = q_sum(q1);
	int	size = (int)q1.size() + (int)q2.size();
	int i = 0;
	int j = 0;
	int val;
	while (i < size && j < size){
		if (sum == sum1){
			return (move);
		}else if (sum < sum1){
			if (i == q1.size())
				return -1;
			val = q1[i++];
			q2.PB(val);
			sum1 -= val;
		}else{
			if (j == q2.size())
				return -1;
			val = q2[j++];
			q1.PB(val);
			sum1 += val;
		}
		move++;
	}
    return -1;
}

#include <iostream>

int main(){
    vector<int> q1;
	q1.PB(1);
	q1.PB(2);
	q1.PB(1);
	q1.PB(2);


    vector<int> q2;
	q2.PB(1);
	q2.PB(10);
	q2.PB(1);
	q2.PB(2);

    int a = solution(q1,q2);
    cout << a << endl;
    return (0);
}