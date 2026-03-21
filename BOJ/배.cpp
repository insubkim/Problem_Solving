#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> crain;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        crain.push_back(c);
    }

    int M;
    cin >> M;
    vector<int> cargo;
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        cargo.push_back(c);
    }

    // sort crain, cargo
    sort(crain.begin(), crain.end());
    sort(cargo.begin(), cargo.end());

    // loop until cargo empty
    //      get cargo out largest among smaller
    //      upper_bound
    int round = 0;
    while (!cargo.empty())
    {
        int del = -1;
        for (int i = 0; i < crain.size(); i++) {
            if (cargo.empty())
                break ;
            
            int some_crain = crain[i];
            vector<int>::iterator it =  upper_bound(cargo.begin(), cargo.end(), some_crain);
            if (it == cargo.end()) {
                cargo.erase(--it);
            } else if (*it <= some_crain || 
                    (it != cargo.begin() && *--it <= some_crain)) {
                cargo.erase(it);
            } else {
                del = del > i ? del : i;
            }
        }

        if (del != -1)
            crain.erase(crain.begin(), crain.begin() + del + 1);

        if (crain.empty()) {
            cout << -1 << endl;
            return 0;
        }

        round++;
    }

    cout << round << endl;
    return 0;
}