#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    REP(i, 0, k-1){
        REP(j, 1, n-1){
            if (arr[j][0] && arr[0][i] == arr[j][i])
                ;
            else
                arr[j][0] = 0;
        }
    }
    int num = 0;
    REP(i, 0, n-1){
        if (arr[i][0])
            num++;
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