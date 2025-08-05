#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first <= b.first;
}

int main()
{
    int req_n, bus_n;

    cin >> req_n >> bus_n;

    int ans = 0;

    vector<pair<int,int>> req;
    vector<pair<int,int>> bus;
    
    map<int, int> avail_bus;

    for (int i = 0; i < req_n; i++)
    {
        int v,w;
        cin >> v >> w;
        pair<int, int> p(w, v);
        req.push_back(p);
    }

    for (int i = 0; i < bus_n; i++)
    {
        int v,w;
        cin >> v >> w;
        pair<int, int> p(w, v);
        bus.push_back(p);
    }

    //sort 
    sort(req.begin(), req.end(), cmp);
    sort(bus.begin(), bus.end(), cmp);

    int bus_idx = 0;

    for (auto &x : req)
    {
        while (bus_idx < bus_n && x.first >= bus[bus_idx].first)
        {
            avail_bus[bus[bus_idx++].second]++;
        }

        auto k = avail_bus.lower_bound((int)(x.second));
        // auto k = avail_bus.lower_bound(1);
        if (k != avail_bus.end())
        {
            ans++;
            k->second--;
            if (k->second == 0)
            {
                avail_bus.erase(k->first);
            }
        }
    }


    cout << ans << endl;
}