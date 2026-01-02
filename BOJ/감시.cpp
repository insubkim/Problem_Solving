#include <bits/stdc++.h>

using namespace std;

#define UP 1 // y : -1, x = 0
#define RIGHT 2 // y = 0, x = 1
#define DOWN 3 // y = 1, x = 0
#define LEFT 4 // y = 0, x = -1

int min_unseen_spot = 2147483647;
int height;
int width;

void fill_line(int y, int x, int dir, int map[][8])
{
    int dirs[5][2] = {
        {0, 0},
        {-1, +0}, // UP
        {+0, +1}, // RIGHT
        {+1, +0}, // DOWN
        {+0, -1} // LEFT
    };

    int dy = dirs[dir][0];
    int dx = dirs[dir][1];

    if (dx == 0)
    {
        for (int i = y; i < height && i >= 0; i += dy)
        {
            if (map[i][x] == 0)
                map[i][x] = '#';
            if (map[i][x] == 6)
                return ;
        }
    }
    else
    {
        for (int i = x; i < width && i >= 0; i += dx)
        {
            if (map[y][i] == 0)
                map[y][i] = '#';
            if (map[y][i] == 6)
                return ;
        }
    }
}

void    paint_one(array<int,3> cctv, int map[][8])
{
    int y = cctv[0];
    int x = cctv[1];
    int dir = cctv[2];

    fill_line(y, x, dir, map);
}

void    paint_two(array<int,3> cctv, int map[][8])
{
    int y = cctv[0];
    int x = cctv[1];
    int dir = cctv[2];

    // dir 1, 3 은 오, 왼
    if (dir == UP || dir == DOWN)
    {
        fill_line(y, x, LEFT, map);
        fill_line(y, x, RIGHT, map);
    }
    else
    {
        fill_line(y, x, UP, map);
        fill_line(y, x, DOWN, map);
    }
}

void    paint_three(array<int,3> cctv, int map[][8])
{
    int y = cctv[0];
    int x = cctv[1];
    int dir = cctv[2];

    // dir 1 은 위, 오
    if (dir == UP)
    {
        fill_line(y, x, UP, map);
        fill_line(y, x, RIGHT, map);
    }// dir 2 은 오, 아래
    else if (dir == LEFT)
    {
        fill_line(y, x, RIGHT, map);
        fill_line(y, x, DOWN, map);
    }// dir 3 은 아래, 왼
    else if (dir == DOWN)
    {
        fill_line(y, x, DOWN, map);
        fill_line(y, x, LEFT, map);
    }// dir 4 은 왼, 위
    else if (dir == RIGHT)
    {
        fill_line(y, x, LEFT, map);
        fill_line(y, x, UP, map);
    }
}

void    paint_four(array<int,3> cctv, int map[][8])
{
    int y = cctv[0];
    int x = cctv[1];
    int dir = cctv[2];

    // dir 1 은 위, 오, 왼
    if (dir == UP)
    {
        fill_line(y, x, UP, map);
        fill_line(y, x, RIGHT, map);
        fill_line(y, x, LEFT, map);
    }// dir 2 은 위, 오, 아래
    else if (dir == LEFT)
    {
        fill_line(y, x, UP, map);
        fill_line(y, x, RIGHT, map);
        fill_line(y, x, DOWN, map);
    }// dir 3 은 오, 아래, 윈
    else if (dir == DOWN)
    {
        fill_line(y, x, RIGHT, map);
        fill_line(y, x, DOWN, map);
        fill_line(y, x, LEFT, map);
    }// dir 4 은 아래, 왼, 위
    else if (dir == RIGHT)
    {
        fill_line(y, x, DOWN, map);
        fill_line(y, x, LEFT, map);
        fill_line(y, x, UP, map);
    }
}

void    paint_five(array<int,3> cctv, int map[][8])
{
    int y = cctv[0];
    int x = cctv[1];
    int dir = cctv[2];

    fill_line(y, x, UP, map);
    fill_line(y, x, RIGHT, map);
    fill_line(y, x, DOWN, map);
    fill_line(y, x, LEFT, map);
}

int get_unseen_spot(int map[8][8], vector<array<int,3>> &cctv)
{
    int map_new[8][8] = {0,};

    memcpy(map_new, map, sizeof(map_new));

    for (auto &c: cctv)
    {
        int y = c[0];
        int x = c[1];

        // 1 위 
        if (map_new[y][x] == 1) paint_one(c, map_new);
        // 2 오른, 왼 
        if (map_new[y][x] == 2) paint_two(c, map_new);
        // 3 위, 오른
        if (map_new[y][x] == 3) paint_three(c, map_new);
        // 4 위 오른 왼
        if (map_new[y][x] == 4) paint_four(c, map_new);
        // 5 모든 쪽
        if (map_new[y][x] == 5) paint_five(c, map_new);
    }

    int unseen_spot = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map_new[i][j] == 0)
                unseen_spot++;
        }
    }
    return unseen_spot;
}

void    solve(int map[8][8], vector<array<int,3>> &cctv, int round)
{
    if (round == cctv.size())
    {
        // 사각지대 계산
        int unseen_stot = get_unseen_spot(map, cctv);
        min_unseen_spot = min(unseen_stot, min_unseen_spot);
        return ;
    }

    // CCTV 회전
    // UP, RIGHT, DOWN, LEFT  
    for (int i = UP; i <= UP + 3; i++)
    {
        cctv[round][2] = i;
        solve(map, cctv, round + 1);
    }
}

int main()
{
    // 완전 탐색
    // cctv의 방향을 모두 한번식 전부 돌린뒤 최소값 판단.

    int N, M;
    cin >> N >> M;
    height = N;
    width = M;

    int map[8][8] = {0,};

    // y, x, 방향 저장
    vector<array<int,3>> cctv;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (1 <= map[i][j] && map[i][j] <= 5)
            {
                array<int, 3> c = {i, j, UP};
                cctv.push_back(c); 
            }
        }
    }

    solve(map, cctv, 0);

    cout << min_unseen_spot << endl;

}