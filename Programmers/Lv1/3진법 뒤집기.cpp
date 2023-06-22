#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
	string a;
	while (n > 0){
		a += n % 3 + '0';
		n /= 3;
	}
	for (auto x : a){
		answer = answer * 3 + x - '0';
	}
    return answer;
}