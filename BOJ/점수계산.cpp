#include <iostream>
#include <algorithm>
#include <set>
#include <utility>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef pair<int, int> pii;


typedef set<pii> spii;

spii s;

typedef set<int> si;
si s1;


int	main(){
    int tmp;
    REP(i, 1, 8){
        cin >> tmp;
        pii p;
        p.first = tmp;
        p.second = i;
        s.insert(p);
    }
    int i = 1;
    int sum = 0;
    for (auto x : s){
        if (i >=4){
            sum += x.first;
            s1.insert(x.second);
        }
        i++;
    }
    cout << sum << endl;
    for (auto x : s1){
        cout << x <<" ";
    }
    cout << endl;
    return (0);
}