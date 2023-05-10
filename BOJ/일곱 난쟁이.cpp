#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef multiset<int> si;

si v;
int arr[10] = {0, };

int    solve(int   k){
    if (k == 8){
        int sum = 0;
        std::multiset<int>::iterator it;
        it = v.begin();
        REP(i, 1, 9){
            if (arr[i]){
                sum += *it;
            }
            it++;
        }
        it = v.begin();
        if (sum == 100){
            REP(i, 1, 9){
                if (arr[i]){
                    cout << *it <<endl;
                }
                it++;
            }
            return (1);
        }
    }else{
        REP(i, k, 9){
            if (!arr[i]){
                arr[i] = 1;
                if (solve(k + 1))
                    return (1);
                arr[i] = 0;
            }
        }
    }
    return (0);
}

int main(){

    int tmp;
    REP(i , 1, 9){
        cin >> tmp;
        v.insert(tmp);
    }
    solve(1);
    return (0);
}

