#include <iostream>

using namespace std;

int main()
{
    int N;
    long long arr[1001] = {0, };


    cin >> N;

    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        if (i % 2)
            sum += arr[i];
        else
            sum -= arr[i];
    }

    long long  prev = sum / 2;
    cout << prev << endl;
    for (int i = 1; i <= N - 1; i++)
    {
        cout << arr[i] - prev << endl;
        prev = arr[i] - prev;
    }

}