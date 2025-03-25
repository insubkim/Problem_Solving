#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;

    cin >> N;

    int result = 0;

    for (int i = 1; i < N / 2 + 1; i++)
    {
        int sum = 0;
        for (int j = i; j <= N / 2 + 1; j++)
        {
            sum += j;
            if (sum == N) result++;
            else if (sum > N) break;
        }
    }

    cout << result + 1 << endl;
}