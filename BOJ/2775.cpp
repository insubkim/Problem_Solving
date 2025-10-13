#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, k, n;

    // k 층 n호

    cin >> T;

    while (T--)
    {
        cin >> k >> n;
        int arr[15][15] = {0,};
        for (int i = 0; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 0) arr[i][j] = j;
                else 
                {
                    int sum = 0;
                    for (int l = 1; l <= j; l++)
                    {
                        sum += arr[i - 1][l];
                    }
                    arr[i][j] = sum;
                }
            }   
        }
        cout << arr[k][n] << endl;
    }
}
