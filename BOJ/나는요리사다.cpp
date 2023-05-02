#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int main()
{
    int score[5] = {0, };
    int tmp;
    REP(i, 0, 19){
        cin >> tmp;
        score[i / 4] += tmp;
    }
    int max = 0;
    int win = -1;
    REP(i, 0, 4){
        if (max < score[i]){
            win = i;
            max = score[i];
        }
    }
    cout << win + 1 << " " << max << endl;
}