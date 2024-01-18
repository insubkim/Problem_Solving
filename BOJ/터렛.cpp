#include <vector>
#include <iostream>
#include <cmath>

#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;

typedef vector<int> vi;

void    solve(void){
    int x1,y1,r1;
    int x2,y2,r2;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    
    // 위치 같을때
    if (x1 == x2 && y1 == y2){
        cout << r1 == r2 ? 1 : 0 << endl;  
        return ;
    }
    
    // 거리가 다를 때, 두 점 거리 구함
    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    
    if (d == r1 + r2) // 두 점 거리와 각각의 위치 합이 같을때
        cout << 1 << endl;
    else if (d > r1 + r2){ // 두 점 거리가 각각의 위치 합보다 클때
        cout << 0 << endl;
    }else{ // 두 점 거리가 각각의 위치 합이 작을때
        if (abs(r1 - r2) < d && d < r1 + r2) { // 두 원이 접하는 곳이 있고 한점에서 접하진 않음.
            cout << 2 << endl;
        } else if (abs(r1 - r2) == d) { // 두 점 거리 뺀값이  반지름 뺀 값
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}