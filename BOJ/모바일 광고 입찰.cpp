#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

bool req_cmp(pair<int, int>a, pair<int, int>b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second <= b.second;
}

int main()
{
    int N, K;

    cin >> N >> K;

    int ans = 0;

    map<int, int> diff;

    int win = 0;
    for (int i = 0; i < N; i++)
    {
        int v,w;
        cin >> v >> w;
        if (v >= w)
            win++;
        else
            diff[w - v]++;
    }

    for (auto &c : diff)
    {
        if (K <= win)
            break ;
        ans = c.first;
        win += c.second;
    }

    cout << ans << endl;
}
