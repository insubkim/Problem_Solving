#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int t;
int nk[2]; 
vi arr;
vi result;

void    search(){
    int diff;
    vi index;

    diff = 0;
    if (nk[1] == 1)
    {
        result.push_back(0);
        return ;
    }
    REP(i, 0, nk[0] - 1){
        if (arr[i] % nk[1] != (i + 1) % nk[1])
        {
            diff++;
            index.push_back(i);
        }
    }
    if (diff == 0)
        result.push_back(0);
    else if (diff != 2)
        result.push_back(-1);    
    else
    {
        int i1 = index[0];
        int i2 = index[1];
        if (arr[i1] % nk[1] == (i2 + 1) % nk[1] && arr[i2] % nk[1] == (i1 + 1) % nk[1])
            result.push_back(1);
        else
            result.push_back(-1);
    }
}

int main(){
    cin >> t;
    //n k
    REP(i, 1, t){
        cin >> nk[0] >> nk[1];
        REP (j, 1, nk[0]){
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }
        search();
        arr.clear();
    }
    vi::iterator iter;
    for (iter = result.begin(); iter != result.end(); iter++)
        cout << *iter << endl;
}