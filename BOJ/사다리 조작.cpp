#include <bits/stdc++.h>

using namespace std;

int N, M, H;

void    check_end(int map[32][32], int ladder_num)
{
    for (int i = 1; i <= N; i++) // x
    {
        int cur = i;
        for (int j = 1; j <= H; j++) // y
        {
            if (map[j][cur] == 1)
            {
                cur++;
            }
            else if (map[j][cur - 1] == 1)
            {
                cur--;
            }
        }
        if (cur != i)
            return ;
    }

    cout << ladder_num << endl;
    exit(0);
}

void    dfs(int ladder_num, int map[32][32], int y, int x, int round)
{
    if (round == ladder_num)
    {
        check_end(map, ladder_num); 
        return ;
    }

    for (int i = y; i <= H; i++)
    {
        int k = x;
        // 다음줄 넘어갔을떄는 1에서 출발
        if (y < i) k = 1;

        for (int j = k; j <= N; j++)
        {
            if (map[i][j] == 1) continue;
            
            if (map[i][j - 1] == 1 || map[i][j + 1] == 1) continue;

            int map_new[32][32];
            memcpy(map_new, map, sizeof(map_new));
            map_new[i][j] = 1;
            dfs(ladder_num, map_new, i, j, round + 1);
        }
    }
}

int main()
{
    cin >> N >> M >> H;

    // 사다리 존재 저장
    // y,x 가 1 이면,
    // y번째 가로선 위치, x - x+1 사이의 세로선에 사다리 존재   
    int map[32][32] = {0,};

    for (int i = 0; i < M; i++)
    {
        int y;
        int x;
        cin >> y >> x;
        map[y][x] = 1; 
    }

    // 0,1,2,3 개의 사다리를 놓아서 해결되는지 확인. 해결된다면 프로그램 종료
    // 백트레이스 실행
    for (int i = 0; i < 4; i++)
    {
        dfs(i, map, 1, 1, 0);
    }


    cout << -1 << endl;
}