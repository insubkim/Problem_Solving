#include <bits/stdc++.h>
#include <unistd.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    char    s[101] = {0,};
    read(0, s, 100);
    int i = 0;
    while (s[i]){
        if ('a' <= s[i] && s[i] <= 'z')
            s[i] = (s[i] - 'a' + 13) % 26 + 'a';
        else if('A' <= s[i] && s[i] <= 'Z')
            s[i] = (s[i] - 'A' + 13) % 26 + 'A';
        i++;
    }
    cout << s << endl;
    return (0);
}