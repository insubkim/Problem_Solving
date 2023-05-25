#include <string>
#include <vector>

#define PB push_back
#define REP(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

vector<int> solution(vector<long long> n) {
    vector<int> a;
    REP(i, 0, (int)n.size() - 1){
        long long k = 0b1;
        while (k > n[i]){
            //해당 이진 트리
        }
    }
    return a;
}

#include <iostream>
int main(){
    vector<long long> a = {63, 111, 95};
    vector<int> i = solution(a);
    for(auto x:i){
        cout << x << endl;
    }
    return 0;
}