#include <iostream>

using namespace std;

int main(){
    char a[501] = {0,};
    int b = read(0, a, 500);
    a[b] = 0;
    int s = 0;
    int e = 0;
    while (b - 3 > s){
        while (a[s] != '\n')
            s++;
        e = s;
        while (--s != '\n')
            write(1, &a[s], 1);        
        s = e + 1;
    }
}