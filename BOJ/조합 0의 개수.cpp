#include <iostream>
#include <algorithm>

using namespace std;

int two = 0;
int five = 0;

void    get_tens(int val)
{
    int bak = val;

    while (val >= 5)
    {
        five += val / 5;
        val /= 5;
    }

    val = bak;
    while (val >= 2)
    {
        two += val / 2;
        val /= 2;
    }
}

void    remove_tens(int val)
{
    int bak = val;

    while (val >= 5)
    {
        five -= val / 5;
        val /= 5;
    }

    val = bak;
    while (val >= 2)
    {
        two -= val / 2;
        val /= 2;
    }
}

int main()
{
    int n,m;

    cin >> n >> m;

    // n! / (n - m)! * m!

    // 1. n! 
    get_tens(n);

    // 2. (n - m)!
    remove_tens(n - m);
    // 3. (m)!
    remove_tens(m);

    cout << min(two, five) << endl;
}