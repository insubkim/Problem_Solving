#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int*> vi;

int t;
int nk[2]; 
vi arr;

void    set_arr()
{
    REP(i, 0, nk[0]){
        if (i * (i - 1) + (nk[0] - i) * (nk[0] - i - 1) == nk[1] * 2)
        {
            int *tmp = (int *)malloc(sizeof(int) * 2);
            tmp[0] = i;
            tmp[1] = nk[0];
            arr.push_back(tmp);
            return;
        }
    }
    arr.push_back(NULL);
}



int main(){
    //t
    cin >> t;
    //n k
    REP(i, 1, t){
        cin >> nk[0] >> nk[1];
        set_arr();
    }
    //out
    //yes or no
    //if yes print arr
    REP (i, 1, t)
    {
        int *tmp = arr[i -1];
        if (!tmp)
            cout << "No" << endl;
        else
        {
            cout << "YES" << endl;
            REP(i, 1, tmp[1])
            {
                if (*tmp > 0)
                {
                    *tmp = *tmp -1;
                    cout << "1";
                }
                else
                    cout << "-1";
                if (i == tmp[1])
                    cout << endl;
                else
                    cout << " ";
            }
        }
    }
}