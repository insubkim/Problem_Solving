#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

vi permutation;
const int n = 4;
bool chosen[n + 1];

void    search(void){
    if (permutation.size() == n){
        vi::iterator iter;
        for (iter = permutation.begin(); iter != permutation.end(); iter++)
            cout << *iter << " ";
        cout << endl;
    }
    else{
        REP(i, 1, n){
            //이미 해당 원소 있으면 넘어가기
            if (chosen[i])
                continue;
            //없으면 해당 원소 넣고 다시 서치 
            chosen[i] = true;
            permutation.push_back(i);
            search();
            //이번에는 해당 원소 빼기
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}


int main(){
    search();
}