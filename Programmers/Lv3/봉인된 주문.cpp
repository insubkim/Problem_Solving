#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string &a, string &b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

string solution(long long n, vector<string> bans) {
    string answer = "";

    sort(bans.begin(), bans.end(), cmp);

    for (auto x: bans)
    {
        unsigned long long num = 0;
        while (x.size() > 1)
        {
            num += x[0] - 'a' + 1;
            num *= 26;

            unsigned long long len = x.size();
            string xx = x.substr(1, len);           
            x = xx;
        }
        num += x[0] - 'a' + 1;
        if (num > n)
            break;
        n++;
    }

    string s;
    while (n)
    {
        s.insert(0, 1, (n - 1) % 26 + 'a');
        n--;
        n /= 26;
    }

    answer = s;
    return answer;
}

int main()
{
    vector<string> s;
    // for (int i = 'a'; i <= 'z'; i++)
    // {
    //     string k;
    //     k.insert(0,1,i);
    //     s.push_back(k);
    // }
    cout << solution(26, s) << endl;
}