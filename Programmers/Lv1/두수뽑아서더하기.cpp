#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
	int arr[201] = {0,};
    vector<int> answer;
	for (int i = 0; i < (int)numbers.size(); i++){
		for (int j = i + 1; j + i < (int)numbers.size(); j++){
			arr[numbers[i] + numbers[j]] = 1;
		}	
	}
	for (int i = 0; i <= 200; i++){
		if (arr[i])
			answer.push_back(i);
	}
    return answer;
}