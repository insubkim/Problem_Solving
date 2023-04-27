#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int t;
int n;
vi arr;
vi result;
int tmp;

int    set_least(int mex)
{
    int least = mex;

    vi::iterator iter;
    for (iter == arr.begin(); iter != arr.end(); iter++){
        if (least )
    }
    return (1);
}

void    search()
{
    int mex, next_mex;
    //get mex
    mex = get_mex();
    //search least bigger than mex val  in arr
    //set those all values to mex val
    if (!set_least(mex)){
        result.push_back(0);
        return ;
    }
    //get mex
    next_mex = get_mex();
    //set result
    if (mex + 1 == next_mex)
        result.push_back(1);
    else
        result.push_back(0);
}

int main()
{
    cin >> t;
    REP(i, 1, t){
        cin >> n;
        REP (i, 1, n){
            c >> tmp;
            arr.push_back(tmp);
        }
        search();
        REP (i, 1, n)   arr.pop_back();
    }
    vi::iterator iter;
    for (iter = result.begin(); iter != result.end(); iter++){
        if (*iter)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
