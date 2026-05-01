#include <iostream>

using namespace std;

// 도시 수
int N;

// 도시간 이동하는데 필요한 비용
int W[17][17];

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> W[i][j];
        }

    }

}