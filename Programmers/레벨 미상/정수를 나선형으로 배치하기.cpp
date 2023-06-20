#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<vector<int>> solution(int n) {
    vector<vector<int>> r(n, vi(n, 0));
    int x = 0;
    int y = 0;
    int d = 1;
    for (int i = 1; i <= n*n; i++){
        r[y][x] = i;
        if (d == 1){
            x++;
            if (x == n || r[y][x]){
                d = 2;
                if (x == n)
                    x = n - 1;
                else
                    x--;
                y++;
            }
        }else if (d == 2){
            y++;
            if (y == n || r[y][x]){
                d = 3;
                if (y == n)
                    y = n - 1;
                else
                    y--;
                x--;
            }
        }else if (d == 3){
            x--;
            if (x == -1 || r[y][x]){
                d = 4;
                if (x == -1)
                    x = 0;
                else
                    x++;
                y--;
            }
        }else {
            y--;
            if (y == -1 || r[y][x]){
                d = 1;
                if (y == -1)
                    y = 0;
                else
                    y++;
                x++;
            }
        }
    }
    return r;
}

#include <iostream>
using namespace std;
int main(){
    vector<vi> a = solution(4);
    for(auto x : a){
        for (auto y : x)
            cout << y;
        cout << endl;
    }
    return 1;
}