#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int main()
{
    int i,j;

    cin >> i >> j;
    //변환
    int tmp = 0;
    REP(k, 1, 3){
        tmp = tmp * 10 + i % 10;
        i /= 10;
    }
    i = tmp;
    tmp = 0;
    REP(k, 1, 3){
        tmp = tmp * 10 + j % 10;
        j /= 10;
    }
    j = tmp;
    //출력
    if (i > j)
        cout << i;
    else
        cout << j;
}