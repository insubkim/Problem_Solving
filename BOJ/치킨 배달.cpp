#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
int map[51][51];

void print(int i)
{
    cout << i << ' ';
}

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int t;
            cin >> t;
            map[i][j] = t;
        }
    }

    vector<int> arr = {1,2,3,4};
    vector<int> tmp = {0,0,1,1};
    do{
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i]) cout << arr[i] << ' ';
        }
        cout << endl;
    } while (next_permutation(tmp.begin(), tmp.end()));

}