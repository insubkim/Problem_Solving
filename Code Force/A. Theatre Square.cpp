#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

typedef vector<int> vi;

int main()
{
    long long n,m,a;
    long long num;

    cin >> n >> m >> a;
    num = (n / a + (1 && (n % a))) * (m / a + (1 && (m % a)));
    cout << num;
    return (0);
}