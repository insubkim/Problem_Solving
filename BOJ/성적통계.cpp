//#include <bits/stdc++.h>
#include <iostream>
#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    int n;
    cin >> n;
    REP(j, 1, n){
        int Max = -1,Min = 101,m,tmp;
        int arr[101] = {0,};
        cin >> m;
        while (m--){
            cin >> tmp;
            if (tmp > Max)
                Max = tmp;
            if (tmp < Min)
                Min = tmp;
            arr[tmp] = 1;
        }
        cout << "Class " << j << endl;
        cout << "Max " << Max << ", Min " << Min << ", Largest gap "; 
        Max = -1;
        tmp = -1;   
        REP(i, 0, 100){
            if (arr[i]){
                if (Max < tmp)
                        Max = tmp;
                tmp = 0;
            }
            if (tmp != -1)
                tmp++;
        }
        if (Max == -1)
            Max = 0;
        cout << Max << endl;
    }
    return (0);
}