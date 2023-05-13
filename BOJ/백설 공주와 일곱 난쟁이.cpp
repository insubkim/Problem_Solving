#include <iostream>

#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    int arr[100] = {0,};
    int in[9] = {0,};
    int n, sum = 0;
    REP(i, 0, 8){
        cin >> n;
        arr[n] = 1;
        in[i] = n;
        sum += n;
    }
    sum -= 100;
    REP(i, 0, 8){
        if (sum - in[i] == in[i] || sum - in[i] <= 0 || sum - in[i] >= 100 || !arr[sum - in[i]])
            cout << in[i] << endl;
    }
    return (0);
}