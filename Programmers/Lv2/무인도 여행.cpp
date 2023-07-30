#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

bool can_visit(vector<string> &maps, int x, int y)
{
    if (0 <= x && x < (int)maps[0].size() && 0 <= y && y < (int)maps.size() && \
        maps[y][x] != 'X')
            return true;
    return false;
}

int    set_visited(queue<pair<int, int>> &q, vector<string> &maps, int x, int y)
{
    int v;

    v = maps[y][x] - '0';
    maps[y][x] = 'X';
    q.push(make_pair(x, y));
    return v;
}

int visit(vector<string> &maps, int x, int y)
{
    int sum = maps[y][x] - '0';
    maps[y][x] = 'X';
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    pair<int, int> pii;
    while (q.size() > 0)
    {
        pii = q.front();
        q.pop();
        if (can_visit(maps, pii.first - 1, pii.second))
            sum += set_visited(q, maps, pii.first - 1, pii.second);
        if (can_visit(maps, pii.first + 1, pii.second))
            sum += set_visited(q, maps, pii.first + 1, pii.second);
        if (can_visit(maps, pii.first, pii.second - 1))
            sum += set_visited(q, maps, pii.first, pii.second -1);
        if (can_visit(maps, pii.first, pii.second + 1))
            sum += set_visited(q, maps, pii.first, pii.second + 1);
    }
    return sum;
}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0; i < (int)maps.size(); i++)
    {
        for (int j = 0; j < (int)maps[1].size(); j++)
        {
            if (maps[i][j] != 'X')
                answer.push_back(visit(maps, j, i));
        }
    }
    if (answer.size() == 0)
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}

#include <iostream>
int main(){
    vector<string> m = {"X591X","X1X5X","X231X", "1XXX1"};
    vector<int> i = solution(m);
    for (auto x : i)
        cout << x << endl;
}