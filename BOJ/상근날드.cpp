#include <vector>
#include <iostream>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define	PB push_back

using namespace std;

typedef	vector<int> vi;

int main(){
    int tmp; 
    int sum;

    cin >> tmp;
    sum = tmp;
    cin >> tmp;
    if (sum > tmp)
        sum = tmp;
    cin >> tmp;
    if (sum > tmp)
        sum = tmp;
    int tmp2;
    cin >> tmp >> tmp2;
    if (tmp < tmp2)
        sum += tmp;
    else
        sum += tmp2;
    cout << sum - 50 << endl;

}