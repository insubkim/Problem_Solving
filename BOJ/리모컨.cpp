#include <vector>
#include <iostream>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define	PB push_back

using namespace std;

typedef	vector<int> vi;

vi	v;
int	N;
int	m;

int	get_over(void){
	int	cur = 100;
	int	n1 = 0;
	while (cur != N && cur <= 500000){
		n1++;
	}
	if (cur)
}

int	set_closest_channel(int *cur){
	int	n1;
	int	n2;
	if (v.size() == 10)
		return (0);
	//cur을 하나는 증가, 하나는 감소 시키면서 가장 가까운 만들수있는 값 구함.
	n1 = get_over();
	n2 = get_below();
	if (n1 < n2){
		set_cur_over(cur);
		return (n1);
	}
	else{
		set_cur_bewlow(cur);
		return (n2);
	}
}

int	main(){
	cin >> N >> m;
	int	tmp;
	REP(i,1,m){
		cin >>tmp;
		v.PB(tmp);
	}
	int	cur = 100;
	int	t1 = 0;
	//채널 누른뒤 증감
	//채널 찾고 누른 횟수 반영
	t1 = set_closest_channel(&cur);
	while (cur == N){
		if (cur > N)
			cur--;
		else
			cur++;
		t2++;
	}
	cur = 100;
	int	t2 = 0;
	//바로 증감
	while (cur != N){
		if (cur > N)
			cur--;
		else
			cur++;
		t2++;
	}
	//둘이 비교
	if (t1 > t2)
		cout << t2 <<endl;
	else
		cout << t1 <<endl;
	return (0);
}