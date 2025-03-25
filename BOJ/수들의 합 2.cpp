#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int result = 0;

    int arr[10001] = {0, };

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += arr[j];
            if (sum == M) result++;
            else if (sum > M) break ;
        }
    }

    cout << result << endl;
}