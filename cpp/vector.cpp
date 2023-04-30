//#include <bits/stdc++.h>
#include <iostream>
#include <vector>


#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

vi arr;
int main()
{
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    //cout << arr.pop_back();
    //cout << arr.pop_back();
    //cout << arr.pop_back();
    REP(i, 0, 2){
        cout << arr[i] <<endl;
    }
    return (0);
}