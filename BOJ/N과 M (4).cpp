#include <iostream>

using namespace std;

// 1 ~ N 까지의 수 중 M 개 선택
int N, M;

// 수열 결과
int selected[10] = {0,};

void    solve(int start, int round) {
    if (round == M){
        for (int i = 1; i <= M; i++) {
            cout << selected[i];
            if (i != M) {
                cout << ' ';
            }
        }
        cout << endl;
        return ;
    }

    for (int i = start; i <= N; i++){
        selected[round + 1] = i; 
        solve(i, round + 1);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        selected[1] = i;
        solve(i, 1);
    }

    return 0;
}