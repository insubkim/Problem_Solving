//#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;
typedef set<int> si;

vi v;
vi  arr;
si s;
int n;
int done;

void    set_search(void){
    done = 0;
    arr.clear();
    REP(i, 1, n){
        arr.push_back(1);
    }
}

int sum(int i, int j){
    int sum = 0;
    REP(k, i, j){
        sum += arr[k];
    }
    return (sum);
}
/*
int get_next(int k){
    for(auto x : s){
        arr.push_back(x);
        int j = k-1;
        //REP(j, k-1, 0){
        while (j >= 0){    
            if (sum(j, k) % (k - j + 1) == 0)
                break ;
            j--;
        }
        if (j == -1)
        {
            s.erase(x);
            return (1);
        }
        arr.pop_back();
    }
    return (0);
}
*/
int get_next(int k){
        for (int j=0; j <= k-1; j++){
            if (arr[j] ==arr[k]){
                return(0);
            }
        }
        int j = k-2;
        while (j >= 0){    
            if (sum(j, k-1) % (k - j + 1) == 0)
                break ;
            j--;
        }
        if (j == -1)
        {
            return (1);
        }
    
    return (0);
}

void    search(int k){
    if (k==n){
        for(auto x : arr){
            v.push_back(x);
        }
        v.push_back(-2);
        done = 1;
    }
    else{
        while (1){
            if (get_next(k))
                search(k+1);
            if (done)
                return ;    
            arr[k] = arr[k] + 1;
            if (arr[k] > n){
                if (k == 0)
                {
                    v.push_back(-1);
                    v.push_back(-2);
                }
                return ;
            }
            
        }
    }
}

int main(){
    int t;

    cin >> t;
    while (t--) { cin >> n; set_search(); search(0);}
    for (int i = 0; i < (int)v.size(); i++){
        if (v[i] == -2)
            cout << endl;
        else{
            cout << v[i];
            if (i+1 != (int)v.size() && v[i+1] != -2)
                cout << " ";
        }
    }
    return (0);
}