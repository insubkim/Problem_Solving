#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>

#include <cmath>

using namespace std;


// 세로, 가로
int N, M;

int map[101][71];

int visited[101][71];

int main(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }   
    }

    // 봉우리를 찾는다.
    // 방문 노드 주변이 자신모다 낮으면 방문 처리
    // 방문 하지 않은 노드 중 봉오리를 찾는다.

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (visited[i][j]) {
                continue ;
            }

            int cur_length = map[i][j];

            

    
        }   
    }


}
