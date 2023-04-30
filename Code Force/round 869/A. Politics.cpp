#include <bits/stdc++.h>
#include <stdlib.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;


vi v;
int n;
int k;
char     **arr;


void    search(void){
    cin >> n >> k;
    arr = (char**)malloc(sizeof(char *) * n);
    REP(i, 0, n-1){
        arr[i] = (char*)malloc(sizeof(char) * (k+1));
        REP(j, 0, k-1){
            cin >> arr[i][j];
        }
        arr[i][k] = 0;
    }
    int num = n;
    REP(i, 0, k-1){
        int tmp = 1;
        REP(j, 1, n-1){
            if (arr[0][i] == arr[j][i])
                tmp++;
            else
            {
                REP(k, i, n-1){
                    arr[j][k] = '0';
                }
            }
        }
        if (tmp < num)
            num = tmp;
    }
    v.push_back(num);
    REP(i, 0, n-1){
        free(arr[i]);
    }
    free(arr);
}


int main()
{
    int t;

    cin >> t;
    while (t--) search();
    for (auto x : v){
        cout << x << endl;
    }
    return (0);
}