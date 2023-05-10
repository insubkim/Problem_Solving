#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

typedef multiset<int> mi;
typedef vector<int> vi;

vi v;
mi m;

int main(){
    int t;
    cin >> t;
    REP(i,1,t){
        int tmp;
        REP(i,1,5){
            cin >> tmp;
            m.insert(tmp);
        }
        std::multiset<int>::iterator it;
        it = m.begin();
        int a,b,c;
        it++;
        a = *it++;
        b = *it++;
        c = *it++;
        if (c - a >= 4){
            v.push_back(0);
        }else{
            v.push_back(a + b + c);
        }
        m.clear();
    }
    REP(i,1,t){
        if (v[i - 1]){
            cout << v[i - 1] << endl;
        }else{
            cout << "KIN" << endl;
        }
    }
    return (0);
}