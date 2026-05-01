#include <set>
#include <vector>
#include <iostream>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back
using namespace std;

typedef	vector<int> vi;

void    solve(void)
{
    long long n;
    cin >> n;
    long long p;
    long long a;
    long long m = INT64_MAX;
    for (long long i = 0; i < n; i++)
    { 
        p = a;
        cin >> a;
        if (i == 0)
            continue ;
        if (p < a && a - p < m)
            m = a - p;
        else if (p > a)
            m = 0;
        else if (p == a && m > 1)
            m = 1;
    }
    
    if (n <= 1)
        m = 0;
    else if (m != 0)
        m++;
    cout << m / 2 + m % 2 << endl;
}


int	main(){
	int	t;
	cin >> t;
	while (t--)	solve();
	return (0);
}