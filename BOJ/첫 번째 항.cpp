#include <iostream>
#include <stdlib.h>

using namespace std;

void    solve(string s)
{
    while (1)
    {
        // 1. check odd
        if (s.size() % 2)
        {
            cout << s << endl;
            return ;
        }
        // 2. check dup
        char prev = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 && prev == s[i])
            {
                cout << s << endl;
                return ;
            }
            if (i % 2)  prev = s[i];
        }

        // 3. solve
        string val;
        int cnt;
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2)
            {
                while (cnt--) val.push_back(s[i]);
            }
            else
            {   
                cnt = s[i] - '0';
            }
        }
        if (!s.compare(val))
        {
            cout <<  val << endl;
            return ;
        }
        s = val;
    }
}

int main(void)
{
    string num;
    int test_cnt = 1;

    while (1)
    {
        cin >> num;
        if (!num.compare("0")) break ;
        cout << "Test " << test_cnt++ << ": ";
        solve(num);
    }
}