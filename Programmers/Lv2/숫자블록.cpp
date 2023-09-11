#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long getGcm(long long v){
    long long i = 2;
    bool f = false;
    int k;
    while (i <= sqrt(v)){
        if (v % i == 0){
            if (v / i <= 10000000)
                return v / i;
            else{
                f = true;
                k = i;
            }
        }
        i++;
    }
    if (f)
        return k;
    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    //가장 큰 최소 공약수 하나 표시
    if (begin == 1){
        answer.push_back(0);
        begin++;
    }
    while (begin <= end){
        answer.push_back(getGcm(begin));
        begin++;
    }
    return answer;
}

#include <iostream>
int main(){
    vector<int> a = solution(1, 100);
    for (int i = 0; i < (int)a.size(); i++)
    cout << a[i] << endl;
}
