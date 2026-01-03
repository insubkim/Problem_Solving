#include <bits/stdc++.h>

using namespace std;

int N,M;
// vector<char> vowel;
// vector<char> consonant;

vector<char> s;

int selected[15];

bool    is_vowel(char c)
{
    // a, e, i, o, u
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'); 
}

void    solve(int round, int idx)
{
    if (round == N)
    {
        int vowel_cnt = 0;
        int consonant_cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (selected[i] == 0) continue;

            if (is_vowel(s[i])) vowel_cnt++;
            else    consonant_cnt++;
        }

        if (vowel_cnt >= 1 && consonant_cnt >= 2)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (selected[i] == 0) continue;

                cout << s[i];
            }
            cout << "\n";
        }
        
        return;
    }

    for (int i = idx; i < M; i++)
    {
        if (selected[i]) continue;
        
        selected[i] = 1;
        solve(round + 1, i + 1);
        selected[i] = 0;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        char c;
        cin >> c;

        s.push_back(c);
        // if (is_vowel(c)) vowel.push_back(c); 
        // else consonant.push_back(c);
    }

    // 모음 각 포함한 상태에서 백 트레킹 실행
    // for (int i = 0; i < vowel.size(); i++)
    // {
    //     solution.push_back(vowel[i]);
    //     solve(0);
    // }

    sort(s.begin(), s.end());
    solve(0, 0);
}
