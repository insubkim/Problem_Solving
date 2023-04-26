#include <bits/stdc++.h>
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;

typedef vector<int> vi;

vi arr;
int len;
vi dp;
int max_length;

void    search(int  k)
{
    if (k == len)
        cout << max_length << endl;
    else{
        //전의 값과 비교 했을때 가장 긴 부분 수열 길이 구하고 dp에 추가
        dp.push_back(1);
        REP(i, 0, k){
            if (arr[i] < arr[k] && dp[i] + 1 > dp[k])
                dp[k] = dp[i] + 1;
        }
        //dp 값과 max_length 비교 후 갱신
        if (dp[k] > max_length)
            max_length = dp[k];
        
        search(k + 1);
    }
}

int main()
{
    int tmp;

    cin >> len;
    REP(i, 0, len){
        cin >> tmp;
        arr.push_back(tmp);
    }
    max_length = 0;
    search(0);
}