#include <string>
#include <vector>

#define PB push_back
#define REP(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

int solve(long long n){
    int t = 0b1;
    if (t == n)
        return 1;
    t = t << 1;
    while (t <= n){
        //in range .. and  if bit operation pass
        if (t <= n && n <= t << 1 | t | ob1 && (n & t == t)){
            return 1;
        }
        
        //make next perfect binary tree
    }
    return 0;
}

vector<int> solution(vector<long long> n) {
    vector<int> a;
    REP(i, 0, (int)n.size() - 1){
        a[i] = solve(n[i]);
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