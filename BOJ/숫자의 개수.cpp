#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    long long r = a * b * c;
    int arr[10] = {0,};
    if (r == 0){
        arr[0] = 1;
    }
    else{
        while (r){
            arr[r%10]++;
            r /= 10;
        }
    }
    REP(i, 0, 9){
        cout << arr[i] << endl;
    }
    return (0);
}