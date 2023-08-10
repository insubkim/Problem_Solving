#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    set<int> arr;
    set<int> tmp;

    arr.insert(x);
    while(arr.size() != 0){
        tmp.clear();
        for (auto x : arr){
            if (x == y)
                return answer;
            if (x + n < y)
                tmp.insert(x + n);
            else if (x + n == y)
                return answer + 1;
            if (x * 2 < y)
                tmp.insert(x * 2);
            else if (x * 2 == y)
                return answer + 1;
            if (x * 3 < y)
                tmp.insert(x * 3);
            else if (x * 3 == y)
                return answer + 1;
        }
        arr = tmp;
        answer++;
    }
    return -1;
}
#include <iostream>
int main(){
    cout << solution(10, 40, 5) << endl;
}