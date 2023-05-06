#include <iostream>
#include <set>

#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back

using namespace std;

typedef set<int> si;

si s;

int main(){
    int t;

    cin >> t;
    int tmp;
    while(t--){
        cin >> tmp;
        s.insert(tmp);
    } 
    set<int>::iterator iter;
    for (iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << endl;
    }
    return (0);
}