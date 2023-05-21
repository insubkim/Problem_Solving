#include <iostream>

using namespace std;

void    solve(void){
    char    a[1001] = {0,};
    cin >> a;
    int i = 0;
    while (a[i])
        i++;
    cout << a[0] << a[--i] << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}