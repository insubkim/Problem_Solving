#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int main(){

    //10번 입력 받아 n k 저장.
    //max 와 비교 저장.
    int max = 0;
    int cur = 0;
    int n,k;
    REP(i, 1, 10){
        cin >> n >> k;
        cur = cur - n + k;
        if (max < cur)
            max = cur;
    }
    cout << max << endl;
    return (0);
}

