#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;

typedef vector<int> vi;

vi subset;
int len;

void    search(int k){
    if (k == len)
    {
        vi::iterator iter;
        for(iter = subset.begin(); iter != subset.end(); iter++)
            cout << *iter + 1<< " ";
        cout << endl;
    }
    else{
        //일단 포함
        subset.push_back(k);
        //다음 서치
        search(k + 1);
        //포함 하지 않기. 벡터에서 빼버리기
        subset.pop_back();
        //다음 서치
        search(k + 1);
    }
}

int main(){
    cin >> len;
    search(0);
    return (0);
}