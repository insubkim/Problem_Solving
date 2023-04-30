#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int main(){
    int arr[100] = {0,};
    int sum = 0;
    int small = -1;
    int n;
    REP(i, 1, 10){
        cin >> n;
        sum += n;
        arr[n / 10]++;
        if (small == -1)
            small = n / 10;
        else if (arr[n / 10] > arr[small])
            small = n / 10;
    }
    cout << sum / 10 << endl << small * 10 << endl;
}