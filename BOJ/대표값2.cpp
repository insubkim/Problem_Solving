#include <set>
#include <iostream>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define	PB push_back

using namespace std;

typedef	multiset<int> si;

si s;

int main(){
    int tmp;
    int sum = 0;
    REP(i, 1, 5){
        cin >> tmp;
        sum += tmp;
        s.insert(tmp);
    }
    cout << sum / 5 << endl;
    int i = 1;
    for (auto x : s){
        if (i == 3){
            cout << x << endl;
            return (0);
        }
        i++;
    }
    return (0);
}