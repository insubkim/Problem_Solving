#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    char a[101] = {0,};
    cin >> a;
    int i = 0;
    int s = 0;
    while (a[i]){
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
            s++;
        i++;
    }
    cout << s << endl;
    return 0;
}