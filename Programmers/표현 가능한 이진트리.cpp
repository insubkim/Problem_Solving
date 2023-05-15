#include <string>
#include <vector>

#define PB push_back

using namespace std;

vector<int> solution(vector<long long> n) {
    vector<int> a;
    long long k = 0b1;
    for (auto x : n){
        if (x == 0b1 || x == 0b10101||x==0b101010101)
            a.PB(1);
        else if (x >= 0b010 && x <= 0b111 && x>>1 & 0b1)
            a.PB(1);
        else if (x >= 0b0101010 && x <= 0b1111111 && x>>1 & 0b1&& x>>3 & 0b1&& x>>5 & 0b1)
            a.PB(1);
        else if (x >= 0b01010101010 && x <= 0b11111111111 && x>>1 & 0b1&& x>>3 & 0b1&& x>>5 & 0b1&& x>>7 & 0b1&& x>>9 & 0b1)
            a.PB(1);
        else
            a.PB(0);
        while (1){
            if (x == k){
                a.PB(1);
                break ;
            }
            k = k << 1;

        }
    }
    return a;
}

#include <iostream>
int main(){
    vector<long long> a = {63,111,95};
    vector<int> i = solution(a);
    for(auto x:i){
        cout << x << endl;
    }
    return 0;
}