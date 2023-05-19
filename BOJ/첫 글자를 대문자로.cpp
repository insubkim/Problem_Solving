//#include <bits/stdc++.h>
#include <unistd.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

//using namespace std;

int main(){
    char c;
    int n;
    scanf("%d", &n);
    while (n--){
        scanf("%c", &(c[0]));
        if ('a' <= c[0] && c[0] <= 'z')
            c[0] -= 32;
        scanf("%s\n", &(c[1]));
        printf("%s\n", c);
    }
    return (0);
}