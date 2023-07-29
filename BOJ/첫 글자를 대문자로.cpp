#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin.ignore();
    while (n--)
    {
        getline(cin, s);
        if (s.size() > 0)
            s[0] = toupper(s[0]);
        cout << s << endl;
    }
    return (0);
}