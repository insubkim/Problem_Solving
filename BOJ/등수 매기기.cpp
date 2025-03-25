#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> ranks;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        ranks.push_back(tmp);
    }

    sort(ranks.begin(), ranks.end());

    long long result = 0;

    for (int i = 1; i <= N; i++)
    {
        result += abs(i - ranks[i - 1]);
    }

    cout << result << endl;
}