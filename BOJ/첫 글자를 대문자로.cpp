#include <bits/stdc++.h>
#include <unistd.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    char c[31] = {0,};
    int b;
    int n;
    cin >> n;
    while (n--){
        b = read(0, &c, 30);
        c[b] = 0;
        if ('a' <= c[0] && c[0] <= 'z')
            c[0] -= 32;
        cout << c;
    }
    return (0);
}