#include <iostream>

using namespace std;

int N, M;

void    solve(int s, int idx, int selected[]) {
    // if round == M
    // return ;
    if (idx == M){
        for (int i = 0; i < M; i++)
            cout << selected[i] << ' ';
        cout << endl;
        return ;
    } else if (idx > M)
        return ;

    selected[idx] = s;

    // recurse
    for (int i = s + 1; i <= N; i++){
        solve(i, idx + 1, selected);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int selected[10] = {0,};
        solve(i, 0, selected);
    }

    return 0;
}