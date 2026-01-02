#include <bits/stdc++.h>

using namespace std;

int N,M;
int city[51][51];

vector<array<int,3>> checken_house;
vector<array<int,2 >> house;

int min_dist = 2147483647;

int cal_dis(void)
{
    int dist_sum = 0;

    for (auto &x: house)
    {
        int min_chicken_dis = 2147483647;

        for (auto &y: checken_house)
        {
            if (y[2] == 0) continue;

            int dist = abs(x[0] - y[0]) + abs(x[1] - y[1]);
            min_chicken_dis = min(min_chicken_dis, dist);
        }
        dist_sum += min_chicken_dis;
    }

    return dist_sum;
}

void    dfs(int select_num, int idx)
{
    if (select_num == M)
    {
        min_dist = min(min_dist, cal_dis());
        return;
    }

    for (int i = idx; i < checken_house.size(); i++)
    {
        checken_house[i][2] = 1;
        dfs(select_num + 1, i + 1);

        checken_house[i][2] = 0;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> city[i][j];
            if (city[i][j] == 2)
                checken_house.push_back({i, j, 0});
            else if (city[i][j] == 1)
                house.push_back({i, j});

        }   
    }

    dfs(0, 0);

    cout << min_dist << endl;
}