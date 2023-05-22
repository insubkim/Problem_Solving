#include <iostream>

using namespace std;

void    solve(void){
    char    a[21] = {0,};
    char    b[21] = {0,};
    cin >> a >> b;
    int i = 0;
    cout << "Distances: ";
    while (a[i]){
        cout << (a[i] <= b[i] ? b[i] - a[i] : b[i] + 26 - a[i])<< " ";
        i++;
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
    return (0);
}